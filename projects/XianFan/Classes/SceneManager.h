//
//  SceneManager.h
//  XianFan
//
//  Created by Bai Ryan on 14-2-21.
//
//

#ifndef __XianFan__SceneManager__
#define __XianFan__SceneManager__

#include "cocos2d.h"

USING_NS_CC;

class SceneManager :public CCNode
{
public:
    static SceneManager *sharedSceneManager();
    static void purge();
    static SceneManager* m_instanceOfSceneManager;
    SceneManager();
    virtual ~SceneManager();
    virtual bool init();
    CREATE_FUNC(SceneManager);
    
    void showLoginScene();
private:
};

#endif /* defined(__XianFan__SceneManager__) */
