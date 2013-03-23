#include <SPI.h>
#include <ble.h>
 
#define DIGITAL_OUT_PIN    4
// right
#define DIGITAL_OUT_PIN2   5
// left


void setup()
{
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(LSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.begin();

  ble_begin();
  
  pinMode(DIGITAL_OUT_PIN, OUTPUT);
}

void loop()
{
  static boolean analog_enabled = false;
  static byte old_state = LOW;
  
  // If data is ready
  while(ble_available())
  {
    // read out command and data
    byte data0 = ble_read();
    byte data1 = ble_read();
    byte data2 = ble_read();
    
    if (data0 == 0x01)  // Command is to control digital out pin
    {
      if (data1 == 0x01)
        digitalWrite(DIGITAL_OUT_PIN, HIGH);
      else
        digitalWrite(DIGITAL_OUT_PIN, LOW);
    }
    else if (data0 == 0x02)  // Command is to control digital out pin 2
    {
      if (data1 == 0x02)
        digitalWrite(DIGITAL_OUT_PIN2, HIGH);
      else
        digitalWrite(DIGITAL_OUT_PIN2, LOW);
    }
  }
    
  if (!ble_connected())
  {
    analog_enabled = false;
    digitalWrite(DIGITAL_OUT_PIN, LOW);
    digitalWrite(DIGITAL_OUT_PIN2, LOW);
  }
  
  // Allow BLE Shield to send/receive data
  ble_do_events();  
}
