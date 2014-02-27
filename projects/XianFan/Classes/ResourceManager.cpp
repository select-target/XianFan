//
//  ResourceManager.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-26.
//
//

#include "ResourceManager.h"
#include "SceneManager.h"

#define kTexture "texture"
#define kPlist "plist"

using namespace std;

ResourceManager* ResourceManager::sharedResourceManager()
{
    if (!m_instanceOfResourceManager) {
        m_instanceOfResourceManager = new ResourceManager();
    }
    return m_instanceOfResourceManager;
}

ResourceManager* ResourceManager::m_instanceOfResourceManager = NULL;

void ResourceManager::purge()
{
    if (m_instanceOfResourceManager) {
        delete m_instanceOfResourceManager;
        m_instanceOfResourceManager = NULL;
    }
}

ResourceManager::ResourceManager()
{
    CCDictionary* dict = CCDictionary::createWithContentsOfFile("resource.plist");
//    dict = (CCDictionary*)dict->objectForKey("resource");
//    m_resourceDict = CCDictionary::createWithDictionary(dict);
//    m_resourceDict->retain();

    CCArray* array = (CCArray*)dict->objectForKey("resource");
    m_sceneArray = CCArray::createWithArray(array);
    m_sceneArray->retain();
    test1 = 5;
}

ResourceManager::~ResourceManager()
{
  //  m_resourceDict->release();
    m_sceneArray->release();
}

CCArray* ResourceManager::getTextureArrayByScene(int sceneType)
{
    CCArray* textureArray = NULL;
    string sceneName;
    
    if (sceneType == kSceneLogin) {
        sceneName = "login";
    }
    
    CCObject* object;
    CCARRAY_FOREACH(m_sceneArray, object)
    {
        CCDictionary* sceneDict = (CCDictionary*)object;
        const CCString* name = sceneDict->valueForKey("name");
        if (strcmp(name->getCString(), sceneName.c_str()) == 0) {
            textureArray = (CCArray*)sceneDict->objectForKey("texture");
            break;
        }
    }
    return textureArray;
}

CCArray* ResourceManager::getPlistArrayByScene(int sceneType)
{
    CCArray* plistArray = NULL;
    
    string sceneName;
    if (sceneType == kSceneLogin) {
        sceneName = "login";
    }

    CCObject* object;
    CCARRAY_FOREACH(m_sceneArray, object)
    {
        CCDictionary* sceneDict = (CCDictionary*)object;
        const CCString* name = sceneDict->valueForKey("name");
        if (strcmp(name->getCString(), sceneName.c_str()) == 0) {
            plistArray = (CCArray*)sceneDict->objectForKey("plist");
            break;
        }
    }
    return plistArray;
}
