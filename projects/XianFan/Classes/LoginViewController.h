//
//  LoginViewController.h
//  XianFan
//
//  Created by Bai Ryan on 14-2-23.
//
//

#import <UIKit/UIKit.h>
#include "cocos2d.h"

USING_NS_CC;

class LoginViewControllerIOSDelegate;
@interface LoginViewControllerIOS : UIViewController

@property (nonatomic, assign) LoginViewControllerIOSDelegate* m_delegate;

@end

class LoginViewControllerIOSDelegate
{
public:
    virtual ~LoginViewControllerIOSDelegate(){}
    virtual void hideViewController(LoginViewControllerIOS* viewController) = 0;
};

class LoginViewController : public CCNode
,public LoginViewControllerIOSDelegate
{
public:
    LoginViewController();
    virtual ~LoginViewController();
    virtual bool init();
    CREATE_FUNC(LoginViewController);
    void show();
    void hide();
    
    virtual void hideViewController(LoginViewControllerIOS* viewController);
private:
    CC_SYNTHESIZE(UINavigationController*, m_viewControllerIOS, ViewControllerIOS);
};

