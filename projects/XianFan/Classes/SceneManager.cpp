//
//  SceneManager.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-21.
//
//

#include "SceneManager.h"
#include "LoginScene.h"

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

void SceneManager::showLoginScene()
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
