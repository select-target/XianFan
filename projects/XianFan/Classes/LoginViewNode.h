//
//  LoginViewNode.h
//  XianFan
//
//  Created by Bai Ryan on 14-2-23.
//
//

#ifndef __XianFan__LoginViewNode__
#define __XianFan__LoginViewNode__

#include "cocos2d.h"

USING_NS_CC;

class LoginViewController;
class LoginViewNode :public CCNode
{
public:
    LoginViewNode();
    virtual ~LoginViewNode();
    virtual bool init();
    CREATE_FUNC(LoginViewNode);
    virtual void onEnter();
    virtual void onExit();
    
    void show();
    void hide();
private:
    LoginViewController *m_loginViewController;
};

#endif /* defined(__XianFan__LoginViewNode__) */
