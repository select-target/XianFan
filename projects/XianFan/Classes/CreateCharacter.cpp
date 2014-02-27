//
//  CreateCharacter.cpp
//  XianFan
//
//  Created by Bai Ryan on 14-2-22.
//
//

#include "CreateCharacter.h"
#include "CCLocalizedString.h"

CreateCharacter::CreateCharacter()
:m_femaleButton()
,m_maleButton()
,m_spawnButton()
,m_selectButton()
{

}

CreateCharacter::~CreateCharacter()
{

}

bool CreateCharacter::init()
{
    if (!CCNode::init())
    {
        return false;
    }
    return true;
}
void CreateCharacter::onEnter()
{
    CCNode::onEnter();
    CCBAnimationManager *animationManager = (CCBAnimationManager*)getUserObject();
    animationManager->setAnimationCompletedCallback(this, callfunc_selector(CreateCharacter::menuSliledFinished));
    animationManager->runAnimationsForSequenceNamed("slide_menu");
}

void CreateCharacter::onExit()
{
    CCNode::onExit();
}

SEL_MenuHandler CreateCharacter::onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "buttonClicked", CreateCharacter::onMenuSelected);
    return NULL;
}

SEL_CCControlHandler CreateCharacter::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "NAME", CreateCharacter::FUNCTION);
    return NULL;
}

bool CreateCharacter::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buttomFemale", CCMenuItemImage*, m_femaleButton);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buttomMale", CCMenuItemImage*,m_maleButton);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "buttonSpawn", CCMenuItemImage*,m_spawnButton);
    return false;
}

bool CreateCharacter::onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue)
{
    return false;
}

void CreateCharacter::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    disabledMenu();
}

void CreateCharacter::menuSliledFinished()
{
    enableMenu();
}

void CreateCharacter::disabledMenu()
{
    m_femaleButton->setEnabled(false);
    m_femaleButton->selected();
    m_maleButton->setEnabled(false);
    m_maleButton->selected();
    m_spawnButton->setVisible(false);
}

void CreateCharacter::enableMenu()
{
    m_femaleButton->setEnabled(true);
    m_femaleButton->unselected();
    
    m_maleButton->setEnabled(true);
    m_maleButton->unselected();
    m_spawnButton->setVisible(true);
}

void CreateCharacter::onMenuSelected(CCObject *sender)
{
    CCNode* button = dynamic_cast<CCNode*>(sender);
    if (button) {
        if (button->getTag() == 1) {
            
        }
        else if (button->getTag() == 2)
        {
        
        }
        else if (button->getTag() == 3)
        {
            if (!m_selectButton) {
                CCMessageBox(CCLocalizedString("no_char_selected", NULL), "");
            }
        }
    }
}
