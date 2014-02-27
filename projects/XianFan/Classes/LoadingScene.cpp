//
//  LoadingScene.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-27.
//
//

#include "LoadingScene.h"
#include "ResourceManager.h"

LoadingScene::LoadingScene():m_delegate()
        ,m_textureToLoad()
        ,m_texturedLoaded()
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
    loadResources();
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

void LoadingScene::loadResources()
{
    CCTextureCache::sharedTextureCache()->removeAllTextures();
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFrames();
    CCArray* textureArray = ResourceManager::sharedResourceManager()->getTextureArrayByScene(m_transitionSceneType);
    m_textureToLoad = textureArray->count();
    m_texturedLoaded = 0;
    CCObject* object;
    CCARRAY_FOREACH(textureArray, object)
    {
        CCString* textureFile = dynamic_cast<CCString*>(object);
        if (textureFile) {
            CCTextureCache::sharedTextureCache()->addImageAsync(textureFile->getCString(), this, callfuncO_selector(LoadingScene::loadingCallBack));
        }
    }
}

void LoadingScene::loadingCallBack(CCObject *obj)
{
    ++ m_texturedLoaded;
    if (m_texturedLoaded == m_textureToLoad) {
        loadSpriteFrame();
        playNextScene();
    }
}

void LoadingScene::loadSpriteFrame()
{

}

void LoadingScene::playNextScene()
{
    if (m_delegate) {
        m_delegate->onLoadingSceneFinished(this, m_transitionSceneType);
    }
}

