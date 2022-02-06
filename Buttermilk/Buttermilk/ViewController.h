//
//  ViewController.h
//  Buttermilk
//
//  Created by Zachary Keffaber on 12/27/21.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

@property (strong, nonatomic) IBOutlet UITableView *myTableView;

@end
