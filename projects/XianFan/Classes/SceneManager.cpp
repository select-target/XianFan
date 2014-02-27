//
//  SceneManager.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-21.
//
//

#include "SceneManager.h"
#include "LoginScene.h"
#include "CreateCharacter.h"

SceneManager* SceneManager::sharedSceneManager()
{
    if (!m_instanceOfSceneManager) {
        m_instanceOfSceneManager = SceneManager::create();
        m_instanceOfSceneManager->retain();
    }
    return m_instanceOfSceneManager;
}

void SceneManager::purge()
{
    if (m_instanceOfSceneManager) {
        m_instanceOfSceneManager->release();
    }
}

SceneManager* SceneManager::m_instanceOfSceneManager = NULL;

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

bool SceneManager::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}

void SceneManager::onLoadingSceneFinished(LoadingScene* loadingScene, int toSceneType)
{
    switch (toSceneType) {
        case kSceneLogin:
        {
            CCScene *scene = CCScene::create();
            CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
            CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
            pLoaderLibrary->registerCCNodeLoader("LoginScene", LoginSceneLoader::loader());
            CCNode *node = ccbReader->readNodeGraphFromFile("ccb/ccbi/login_ui.ccbi");
            ccbReader->release();
            scene->addChild(node);
            CCDirector::sharedDirector()->replaceScene(scene);
            m_currentSceneType = kSceneLogin;
        }
            break;
        default:
            break;
    }
}

void SceneManager::showLoadingScene(int sceneType)
{
    CCScene *scene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("LoadingScene", LoadingSceneLoader::loader());
    LoadingScene* loadingScene = (LoadingScene*)ccbReader->readNodeGraphFromFile("ccb/ccbi/loading_ui.ccbi");
    ccbReader->release();
    scene->addChild(loadingScene);
    loadingScene->setDelegate(this);
    loadingScene->setTransitionSceneType(sceneType);
    if (CCDirector::sharedDirector()->getRunningScene()) {
        CCDirector::sharedDirector()->replaceScene(scene);
    }
    else
    {
        CCDirector::sharedDirector()->runWithScene(scene);
    }
}

void SceneManager::showLoginScene()
{
    showLoadingScene(kSceneLogin);
}

void SceneManager::showCreateCharacter()
{
    CCScene *scene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("CreateCharacter", CreateCharacterLoader::loader());
    CCNode *node = ccbReader->readNodeGraphFromFile("ccb/ccbi/create_character_ui.ccbi");
    ccbReader->release();
    scene->addChild(node);
    CCDirector::sharedDirector()->pushScene(scene);
    m_currentSceneType = kSceneCreateCharacter;
}

void SceneManager::showSelectCharacter()
{
    CCScene *scene = CCScene::create();
    CCNodeLoaderLibrary *pLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(pLoaderLibrary);
    pLoaderLibrary->registerCCNodeLoader("LoginScene", LoginSceneLoader::loader());
    CCNode *node = ccbReader->readNodeGraphFromFile("ccb/ccbi/login_ui.ccbi");
    ccbReader->release();
    scene->addChild(node);
    CCDirector::sharedDirector()->runWithScene(scene);
}

void SceneManager::returnLoginScene()
{

}

