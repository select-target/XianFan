//
//  LoginViewController.m
//  XianFan
//
//  Created by Bai Ryan on 14-2-23.
//
//

#include "LoginViewController.h"
#import "EAGLView.h"
#include "CCLocalizedString.h"

LoginViewController::LoginViewController():m_viewControllerIOS()
{

}

LoginViewController::~LoginViewController()
{

}

bool LoginViewController::init()
{
    if (!CCNode::init()) {
        return false;
    }
    return true;
}

void LoginViewController::show()
{
    if (!m_viewControllerIOS) {
        LoginViewControllerIOS *viewController = [[LoginViewControllerIOS alloc] init];
        viewController.m_delegate = this;
        m_viewControllerIOS = [[UINavigationController alloc] initWithRootViewController:viewController];
        
        CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
        m_viewControllerIOS.view.frame = CGRectMake(0, 0, screenSize.width/2, screenSize.height/2);
        [[EAGLView sharedEGLView] addSubview: m_viewControllerIOS.view];
    }
}

void LoginViewController::hide()
{
    if (m_viewControllerIOS) {
        [m_viewControllerIOS.view removeFromSuperview];
        m_viewControllerIOS = NULL;
    }
}

void LoginViewController::hideViewController(LoginViewControllerIOS* viewController)
{
    CCCallFunc *callHide = CCCallFunc::create(this,callfunc_selector( LoginViewController::hide));
    runAction(callHide);
}

@interface LoginViewControllerIOS ()

@end

@implementation LoginViewControllerIOS
@synthesize m_delegate;

-(id) init
{
    if ((self = [super init])) {
        m_delegate = nil;
        
        self.view.backgroundColor = [UIColor whiteColor];
        self.navigationItem.title = [NSString stringWithUTF8String:CCLocalizedString("sign_up", NULL)];
        self.navigationItem.backBarButtonItem = [[UIBarButtonItem alloc] init];
        NSString *backString = [NSString stringWithUTF8String:CCLocalizedString("return", NULL)];
        UIBarButtonItem *button = [[UIBarButtonItem alloc] initWithTitle:backString style:UIBarButtonItemStylePlain target:self action:@selector(performButton:)];
        self.navigationItem.leftBarButtonItem = button;
    }
    return self;
}
                                   
-(void) performButton:(id)sender
{
    m_delegate->hideViewController(self);
    
    if (m_delegate) {
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
