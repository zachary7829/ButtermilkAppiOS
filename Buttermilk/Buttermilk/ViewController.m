//
//  ViewController.m
//  Buttermilk
//
//  Created by Zachary Keffaber on 12/27/21.
//

#import "ViewController.h"
#import "libbuttermilk/libbuttermilk.h"
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *ButtermilkText;
@property (weak, nonatomic) IBOutlet UILabel *DisplayShortcutOutputDemoText;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}
- (IBAction)ButterToShortcut:(id)sender {
    NSLog(@"libbuttermilk ready...");
    const char *input = [[self.ButtermilkText text] UTF8String];
    char *output = buttermilk(input);
    NSLog(@"%s",output);
    NSString *output2 = [NSString stringWithFormat:@"%s", output];
    if ([@"test" isEqualToString:[self.ButtermilkText text]])
    {
        NSLog(@"Success");
        [self.DisplayShortcutOutputDemoText setText:@"Success"];
    }
    
}


@end