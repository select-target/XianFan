//
//  LoginScene.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-21.
//
//

#include "LoginScene.h"

LoginScene::LoginScene()
{

}

LoginScene::~LoginScene()
{

}

bool LoginScene::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void LoginScene::onEnter()
{
    CCNode::onEnter();
}

void LoginScene::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler LoginScene::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", LoginScene::FUNCTION);
    return NULL;
}

SEL_CCControlHandler LoginScene::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", LoginScene::FUNCTION);
    return NULL;
}

bool LoginScene::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "NAME", TYPE,VALUE);
    return false;
}

bool LoginScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void LoginScene::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    
    
}
