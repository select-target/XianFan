//
//  LoginScene.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-21.
//
//

#include "LoginScene.h"
#include "Actor.h"

#define kBackgroundLoopImage "graphic/ui/login_allbd.jpg"
#define kBackgroundLoopImageCount 2

#define kShiningEffectPlist "graphic/effect/logineff1.plist"
#define kShiningEffectFrameDefault "eff_cj1_00000.png"
#define kShiningEffectFrame "eff_cj1_000"

LoginScene::LoginScene()
:m_backgroundBacthNode()
,m_shiningEffect()
,m_holoEffect()
{

}

LoginScene::~LoginScene()
{

}

bool LoginScene::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void LoginScene::onEnter()
{
    CCNode::onEnter();
    scheduleUpdate();
}

void LoginScene::onExit()
{
    CCNode::onExit();
    unscheduleUpdate();
}

SEL_MenuHandler LoginScene::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "NAME", LoginScene::FUNCTION);
    return NULL;
}

SEL_CCControlHandler LoginScene::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", LoginScene::FUNCTION);
    return NULL;
}

bool LoginScene::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    if (strcmp(pMemberVariableName, "background_batchnode") == 0) {
      
        m_backgroundBacthNode = CCSpriteBatchNode::create(kBackgroundLoopImage, kBackgroundLoopImageCount);
        for (int i=0; i<kBackgroundLoopImageCount; i++) {
            CCSprite* background = CCSprite::create(kBackgroundLoopImage);
            m_backgroundBacthNode->addChild(background);
            background->setAnchorPoint(CCPointZero);
            background->setPosition(ccp(i*background->getContentSize().width,0));
        //    background->setPosition(CCPointZero);
        }
        pNode->addChild(m_backgroundBacthNode);
    }
    
    return false;
}

bool LoginScene::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}


void LoginScene::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    loadResource();
    addEffect();
}

void LoginScene::loadResource()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(kShiningEffectPlist);
}

void LoginScene::addEffect()
{
    AnimationParam param;
    param.frameName = kShiningEffectFrame;
    param.interval = 0.1f;
    param.loops = -1;
    param.restoreFirstFrame = true;
    param.count = 29;

    Actor* actor = Actor::createWithSpriteFrameNameAndKey(kShiningEffectFrameDefault, &param, "shining");
    addChild(actor);
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    actor->setAnchorPoint(ccp(0.5f, 1.0f));
    actor->setPosition(ccp(screenSize.width/2,screenSize.height));
    actor->switchToFormAnimatedByKey("shining");
}

void LoginScene::update(float dt)
{
    CCNode::update(dt);
    if (m_backgroundBacthNode) {
        CCObject* object;
        CCARRAY_FOREACH(m_backgroundBacthNode->getChildren(), object)
        {
            CCSprite* sprite = (CCSprite*)object;
            sprite->setPosition(ccp(sprite->getPositionX() - 0.5, sprite->getPositionY()));
            if (sprite->getPositionX() <= - sprite->getContentSize().width) {
                sprite->setPosition(ccp((kBackgroundLoopImageCount-1)*sprite->getContentSize().width, 0));
            }
        }
    }
}

