//
//  ViewController.m
//  Buttermilk
//
//  Created by Zachary Keffaber on 12/27/21.
//

#import "ViewController.h"
#import "libbuttermilk/libbuttermilk.h"
@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextView *ButtermilkText;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}
- (IBAction)ShortcutToButter:(id)sender {
    NSLog(@"libbuttermilk ready...");
    const char *input = [[self.ButtermilkText text] UTF8String];
    const char *output = buttermilk(2, input);
    NSString *output2 = [NSString stringWithFormat:@"%s", output];
    [self.ButtermilkText setText:output2];
}
- (IBAction)ButterToShortcut:(id)sender {
    NSLog(@"libbuttermilk ready...");
    const char *input = [[self.ButtermilkText text] UTF8String];
    const char *output = buttermilk(1, input);
    NSString *output2 = [NSString stringWithFormat:@"%s", output];
    [self.ButtermilkText setText:output2];
}


@end
