#include "ScalableMenuItemImageLoader.h"

#define PROPERTY_NORMALDISPLAYFRAME "normalSpriteFrame"
#define PROPERTY_SELECTEDDISPLAYFRAME "selectedSpriteFrame"
#define PROPERTY_DISABLEDDISPLAYFRAME "disabledSpriteFrame"


void ScalableMenuItemImageLoader::onHandlePropTypeSpriteFrame(cocos2d::Node * pNode,
															  cocos2d::Node * pParent,
															  const char * pPropertyName,
															  cocos2d::SpriteFrame * pSpriteFrame,
															  cocosbuilder::CCBReader * ccbReader) {
	if(strcmp(pPropertyName, PROPERTY_NORMALDISPLAYFRAME) == 0) {
		if(pSpriteFrame != NULL) {
			((cocos2d::MenuItemImage *)pNode)->setNormalSpriteFrame(pSpriteFrame);
		}
	}
	else if(strcmp(pPropertyName, PROPERTY_SELECTEDDISPLAYFRAME) == 0) {
		if(pSpriteFrame != NULL) {
			((cocos2d::MenuItemImage *)pNode)->setSelectedSpriteFrame(pSpriteFrame);
		}
	}
	else if(strcmp(pPropertyName, PROPERTY_DISABLEDDISPLAYFRAME) == 0) {
		if(pSpriteFrame != NULL) {
			((cocos2d::MenuItemImage *)pNode)->setDisabledSpriteFrame(pSpriteFrame);
		}
	}
	else {
		MenuItemLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
	}
}
