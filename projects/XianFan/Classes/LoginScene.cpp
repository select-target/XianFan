//
//  LoginScene.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-21.
//
//

#include "LoginScene.h"
#include "Actor.h"
#include "SceneManager.h"
#include "RCMessage.h"
#include "netmsg.pb.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#include <stdio.h>
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#endif
using namespace MessageCode;

#define kBackgroundLoopImage "graphic/ui/login_allbd.jpg"
#define kBackgroundLoopImageCount 2

#define kShiningPlist "graphic/effect/logineff1.plist"
#define kShiningFrameDefault "eff_cj1_00000.png"
#define kShiningFrame "eff_cj1_000"

#define kHaloImageDefault "graphic/effect/logineff2/eff_cj2_00000.png"
#define kHaloImage "graphic/effect/logineff2/eff_cj2_000"

#define kButterFlyPlist "graphic/effect/logineff4.plist"
#define kButterFlyFrameDefault  "eff_jc4_00000.png"
#define kButterFlyFrame "eff_jc4_000"

LoginScene::LoginScene()
:m_backgroundBacthNode()
,m_shining()
,m_halo()
,m_startButton()
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
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "buttonClicked", LoginScene::onButtonClicked);
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
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "startButton", CCNode*, m_startButton);
    
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
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    addLoginViewNode();
#endif
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

void LoginScene::addLoginViewNode()
{
    m_loginViewNode = LoginViewNode::create();
    addChild(m_loginViewNode);
}

#endif

void LoginScene::loadResource()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(kShiningPlist);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(kButterFlyPlist);
}

void LoginScene::addEffect()
{
    AnimationParam param;
    param.frameName = kShiningFrame;
    param.interval = 0.1f;
    param.loops = -1;
    param.restoreFirstFrame = true;
    param.startIndex = 0;
    param.endIndex = 28;

    m_shining = Actor::createWithSpriteFrameNameAndKey(kShiningFrameDefault, &param, "shining");
    addChild(m_shining);
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    m_shining->setAnchorPoint(ccp(0.5f, 1.0f));
    m_shining->setPosition(ccp(screenSize.width/2,screenSize.height));
    m_shining->switchToFormAnimatedByKey("shining");
    
    param.frameName = kHaloImage;
    param.startIndex = 0;
    param.endIndex = 29;
    m_halo = Actor::createWithSpriteImageNameAndKey(kHaloImageDefault, &param, "haloing");
    addChild(m_halo);
    m_halo->setAnchorPoint(ccp(0.5f, 1.0f));
    m_halo->setPosition(ccp(screenSize.width/2, screenSize.height));
    m_halo->switchToFormAnimatedByKey("haloing");
    
    param.frameName = kButterFlyFrame;
    param.startIndex = 0;
    param.endIndex = 30;
    m_bufferFly = Actor::createWithSpriteFrameNameAndKey(kButterFlyFrameDefault, &param, "bufferfly");
    addChild(m_bufferFly);
    if (m_startButton) {
        //CCPoint buttonPoint = m_startButton->convertToWorldSpace(m_startButton->getPosition());
        CCPoint pos = m_startButton->getPosition();
        CCNode* parent = m_startButton->getParent();
        while (parent != this) {
            pos = pos + parent->getPosition();
       //     CCLog("parent pos :%f", parent->getPositionX());
            parent = parent->getParent();
        }
        m_bufferFly->setPosition(pos);
    }
    m_bufferFly->switchToFormAnimatedByKey("bufferfly");
}

void LoginScene::onButtonClicked(CCObject* sender)
{
    CCNode* button = (CCNode*)sender;
    if (button->getTag() == 2) {
        SceneManager::sharedSceneManager()->showCreateCharacter();
    }
    else if(button->getTag() == 1)
    {
        //ProtoLoginReq* req = new ProtoLoginReq();
        //req->set_authid(1);
        //delete req;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JniMethodInfo minfo;
		bool isHave = JniHelper::getStaticMethodInfo(minfo, "com/ryanflees/xianfan/XianFan",
				"getInstance","()Lcom/ryanflees/xianfan/XianFan;");
		jobject jobj = NULL;
		if (isHave) {
			CCLOG("has method getInstance");
			jobj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
		}
		if(jobj){
			CCLOG("abtained register activity");
			JniHelper::getMethodInfo(minfo,"com/ryanflees/xianfan/XianFan","showCustomView","()V");
			minfo.env->CallVoidMethod(jobj, minfo.methodID);
		}
		else
		{
			CCLOG("activity null");
		}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        m_loginViewNode->show();
#endif
    }
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

