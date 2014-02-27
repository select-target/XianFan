//
//  LoginViewNode.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-23.
//
//

#include "LoginViewNode.h"
#include "LoginViewController.h"

LoginViewNode::LoginViewNode()
{

}

LoginViewNode::~LoginViewNode()
{

}

bool LoginViewNode::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    
    m_loginViewController = LoginViewController::create();
    addChild(m_loginViewController);
    return true;
}

void LoginViewNode::onEnter()
{
    CCNode::onEnter();
}

void LoginViewNode::onExit()
{
    CCNode::onExit();
}

void LoginViewNode::show()
{
    m_loginViewController->show();
}

void LoginViewNode::hide()
{
    m_loginViewController->hide();
}
