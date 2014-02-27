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
#include "LoadingScene.h"

USING_NS_CC;

enum
{
    kSceneNone = 0,
    kSceneLogin,
    kSceneCreateCharacter,
    kSceneSelectCharacter,
    kSceneWorldScene,
    kSceneCityScene,
    kSceneBattleScene
};

class SceneManager : public CCNode
                   , public LoadingSceneDelegate
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
    void showLoadingScene(int sceneType);
    void showCreateCharacter();
    void showSelectCharacter();
    void returnLoginScene();
    
    // LoadingSceneDelegate
    virtual void onLoadingSceneFinished(LoadingScene* loadingScene, int toSceneType);
private:
    CC_SYNTHESIZE_READONLY(int, m_currentSceneType, CurrentSceneType);
};

#endif /* defined(__XianFan__SceneManager__) */
