#ifndef __ScalableMenuItemImageLoader_h__
#define __ScalableMenuItemImageLoader_h__

#include "cocosbuilder/CocosBuilder.h"
#include "ScalableMenuItemImage.h"

/* Forward declaration. */
class CCBReader;

class ScalableMenuItemImageLoader : public cocosbuilder::MenuItemLoader {
public:
	/**
	 * @js NA
	 * @lua NA
	 */
	virtual ~ScalableMenuItemImageLoader() {};
	/**
	 * @js NA
	 * @lua NA
	 */
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ScalableMenuItemImageLoader, loader);
	
protected:
	/**
	 * @js NA
	 * @lua NA
	 */
	CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ScalableMenuItemImage);
	/**
	 * @js NA
	 * @lua NA
	 */
	virtual void onHandlePropTypeSpriteFrame(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::SpriteFrame * pSpriteFrame, cocosbuilder::CCBReader * ccbReader);
};

#endif //__ScalableMenuItemImageLoader_h__
