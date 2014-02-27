//
//  LoadingScene.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-24.
//
//

#if 0
#include "LoadingScene.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

#define kLoadingDelayTime 0.1f

LoadingScene::LoadingScene():m_delegate()
            ,m_transitionSceneType(kSceneNone)
{

}

LoadingScene::~LoadingScene()
{

}

bool LoadingScene::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void LoadingScene::onEnter()
{
    CCNode::onEnter();
    CCCallFunc *loadRes = CCCallFunc::create(this, callfunc_selector(LoadingScene::loadResources));
    CCFiniteTimeAction *seq = CCSequence::create(CCDelayTime::create(kLoadingDelayTime),loadRes,NULL);
    runAction(seq);
}

void LoadingScene::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler LoadingScene::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", LoadingScene::FUNCTION);
    return NULL;
}

SEL_CCControlHandler LoadingScene::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", LoadingScene::FUNCTION);
    return NULL;
}

bool LoadingScene::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "NAME", TYPE,VALUE);
    return false;
}

bool LoadingScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void LoadingScene::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    
    
}

static void* loadThreadFunction(void* data)
{
    CCTextureCache::sharedTextureCache()->removeAllTextures();
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFrames();
    LoadingScene* loadingScene = (LoadingScene*)data;
    CCArray* textureArray = ResourceManager::sharedResourceManager()->getTextureArrayByScene(loadingScene->getTransitionSceneType());
    CCObject* object;
    CCARRAY_FOREACH(textureArray, object)
    {
        CCString* textureFile = dynamic_cast<CCString*>(object);
        if (textureFile) {
            CCTextureCache::sharedTextureCache()->addImageAsync(textureFile->getCString(),NULL,NULL);
        }
    }
    loadingScene->loadResourceFinished();
    return NULL;
}

void LoadingScene::loadResourceFinished()
{
    CCCallFunc *callNext = CCCallFunc::create(this, callfunc_selector(LoadingScene::playNextScene));
    CCFiniteTimeAction *seq = CCSequence::create(CCDelayTime::create(kLoadingDelayTime),callNext,NULL);
    runAction(seq);
}

void LoadingScene::loadResources()
{
    int errCode = 0;
    do {
        pthread_attr_t addr;
        errCode = pthread_attr_init(&addr);
        
        CC_BREAK_IF(errCode != 0);
        
        errCode = pthread_attr_setdetachstate(&addr, PTHREAD_CREATE_DETACHED);
        
        if (errCode != 0) {
            pthread_attr_destroy(&addr);
            break;
        }
        errCode = pthread_create(&threadLoadResource, &addr, loadThreadFunction, this);
    } while (0);
}

void LoadingScene::loadSpriteFrame()
{
    CCObject* object;
    CCArray* plistArray = ResourceManager::sharedResourceManager()->getPlistArrayByScene(m_transitionSceneType);
    CCARRAY_FOREACH(plistArray, object)
    {
        CCString* plistFile = dynamic_cast<CCString*>(object);
        if (plistFile) {
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plistFile->getCString());
        }
    }
}

void LoadingScene::playNextScene()
{
    loadSpriteFrame();
    if (m_delegate) {
        m_delegate->onLoadingSceneFinished(this, m_transitionSceneType);
    }
}
#endif
