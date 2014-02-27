//
//  CreateCharacter.h
//  XianFan
//
//  Created by Bai Ryan on 14-2-22.
//
//

#ifndef __XianFan__CreateCharacter__
#define __XianFan__CreateCharacter__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CreateCharacter : public CCNode
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCNodeLoaderListener
{
public:
    CreateCharacter();
    virtual ~CreateCharacter();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CreateCharacter, create);
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader);
private:
    void menuSliledFinished();
    void disabledMenu();
    void enableMenu();
    void onMenuSelected(CCObject* sender);
    CCMenuItemImage* m_femaleButton;
    CCMenuItemImage* m_maleButton;
    CCMenuItemImage* m_spawnButton;
    CCMenuItemImage* m_selectButton;
};

class CreateCharacterLoader : public CCNodeLoader{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( CreateCharacterLoader, loader );
    
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( CreateCharacter);
};


#endif /* defined(__XianFan__CreateCharacter__) */
