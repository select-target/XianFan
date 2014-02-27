//
//  Actor.h
//  ComicWars
//
//  Created by Bai Ryan on 13-11-18.
//
//

#ifndef __Actor__
#define __Actor__

#include <iostream>
#include "cocos2d.h"

#define kSubFormName "form_name"
#define kSubFromSprite "sprite"
#define kSubFormAnimationKey "aniamtion"

typedef struct
{
    std::string frameName;
    int startIndex;
    int endIndex;
    int loops;
    bool restoreFirstFrame;
    float interval;
}AnimationParam;

class Actor : public cocos2d::CCSprite
{
public:
    Actor():m_dictionary(NULL)
    ,m_isFlipX(false)
    ,m_sequence()
    {
        
    }
    
    ~Actor();
    
    static Actor *createWithSpriteImageNameAndKey(const char* imageName, AnimationParam *animationParam, const char *key);
    virtual bool initWithSpriteImageNameAndKey(const char* imageName, AnimationParam *animationParam, const char *key);
    
    static Actor *createWithSpriteFrameNameAndKey(const char *frameName, AnimationParam *animationParam, const char *key);
    virtual bool initWithSpriteFrameNameAndKey(const char *frameName,AnimationParam *animationParam, const char *key);
    
    void addSubFormWithSpriteFrameNameAndKey(const char *frameName,AnimationParam *animationParam, const char *key);
    
    void switchToFormAnimatedByKey(const char *key);
    void switchToFormAnimatedByKey(const char *key, cocos2d::CCCallFunc *callback);
    
    cocos2d::CCArray *getAllFormKeys();
    
    int getFormCount();
    
    virtual void update(float delta);
    
    cocos2d::CCRect getUnitRect();
    
    void pauseAnimation();
    void resumeAnimation();
    
protected:
    
    cocos2d::CCFiniteTimeAction *m_sequence;
    
    CC_SYNTHESIZE(bool, m_isFlipX, IsFlipX);
    CC_SYNTHESIZE(bool, m_isActive, IsActive);
    
    cocos2d::CCDictionary *m_dictionary;
};



#endif /* defined(__Actor__) */
