//
//  LoginScene.h
//  XianFan
//
//  Created by Bai Ryan on 14-2-21.
//
//

#ifndef __XianFan__LoginScene__
#define __XianFan__LoginScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "LoginViewNode.h"
#endif

class Actor;
class LoginScene : public CCNode
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
{
public:
    LoginScene();
    virtual ~LoginScene();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LoginScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
    
    virtual void update(float dt);
private:
    void loadResource();
    void addEffect();
    void onButtonClicked(CCObject* sender);
    
    CCSpriteBatchNode* m_backgroundBacthNode;
    CCNode* m_startButton;
    Actor* m_shining;
    Actor* m_halo;
    Actor* m_bufferFly;
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    void addLoginViewNode();
    LoginViewNode* m_loginViewNode;
#endif
};

class LoginSceneLoader : public CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( LoginSceneLoader, loader );
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( LoginScene);
};


#endif /* defined(__XianFan__LoginScene__) */
