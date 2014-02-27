//
//  LoadingScene.h
//  XianFan
//
//  Created by Bai Ryan on 14-2-24.
//
//

#ifndef __XianFan__LoadingScene__
#define __XianFan__LoadingScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class LoadingScene;
class LoadingSceneDelegate
{
public:
    virtual void onLoadingSceneFinished(LoadingScene* loadingScene, int toSceneType) = 0;
};

class LoadingScene : public CCNode
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
{
public:
    LoadingScene();
    virtual ~LoadingScene();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LoadingScene, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
    
    void loadResourceFinished();
private:
    void loadResources();
    void loadSpriteFrame();
    void playNextScene();
    
    CC_SYNTHESIZE(int, m_transitionSceneType, TransitionSceneType);
    CC_SYNTHESIZE(LoadingSceneDelegate*, m_delegate, Delegate);
    pthread_t threadLoadResource;
};

class LoadingSceneLoader : public CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( LoadingSceneLoader, loader );
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( LoadingScene);
};


#endif /* defined(__XianFan__LoadingScene__) */
