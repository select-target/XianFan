//
//  ResourceManager.h
//  XianFan
//
//  Created by Bai Ryan on 14-2-26.
//
//

#ifndef __XianFan__ResourceManager__
#define __XianFan__ResourceManager__

#include "cocos2d.h"

USING_NS_CC;

class ResourceManager
{
public:
    static ResourceManager* sharedResourceManager();
    static ResourceManager* m_instanceOfResourceManager;
    static void purge();
    ResourceManager();
    ~ResourceManager();
    CCArray* getTextureArrayByScene(int sceneType);
    CCArray* getPlistArrayByScene(int sceneType);
private:
    CCDictionary* m_resourceDict;
    CCArray* m_sceneArray;
    int test1;
};

#endif /* defined(__XianFan__ResourceManager__) */
