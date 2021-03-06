//
//  TableViewController.h
//  SimpleControl
//
//  Created by Cheong on 7/11/12.
//  Copyright (c) 2012 RedBearLab. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BLE.h"

@interface TableViewController : UITableViewController <BLEDelegate>
{
    IBOutlet UIButton *btnConnect;
    IBOutlet UISwitch *swDigitalOut;
    IBOutlet UISwitch *swDigitalOut2;
    IBOutlet UIActivityIndicatorView *indConnecting;
    IBOutlet UILabel *lblRSSI;
}

@property (strong, nonatomic) BLE *ble;

@end
