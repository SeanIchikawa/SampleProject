#ifndef __SimpleView_h__
#define __SimpleView_h__

#include "cocos2d.h"
#include "ScalableMenuItemImageLoader.h"
#include "cocosbuilder/CocosBuilder.h"


class SimpleView :
	public cocos2d::Node,
	public cocosbuilder::CCBSelectorResolver,
	public cocosbuilder::CCBMemberVariableAssigner,
	public cocosbuilder::NodeLoaderListener,
	public cocosbuilder::CCBAnimationManagerDelegate
{
public:
	static SimpleView* create(cocos2d::Node* pParent, cocosbuilder::CCBReader* ccbReader);
	static SimpleView* createLayer();
	
private:
	SimpleView();
	virtual ~SimpleView();
	
	bool init(cocos2d::Node* parent, cocosbuilder::CCBReader* ccbReader);

	void onClick(cocos2d::Ref* snder) {
		cocos2d::log("SimpleView::onClick(): called");
		
		cocos2d::Director::getInstance()->end();
		exit(0);
	}

	cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName) override;
	
	bool onAssignCCBMemberVariable(cocos2d::Ref* pTarget, const char* pMemberVariableName, cocos2d::Node* pNode) override {
		return false;
	}
	
	bool onAssignCCBCustomProperty(cocos2d::Ref* ptarget, const char* pMemberVariableName, const cocos2d::Value& pValue) override {
		return false;
	};

	cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Ref* pTarget, const char* pSelectorName) override {
		return nullptr;
	};
	cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref* pTarget, const char* pSelectorName) override {
		return nullptr;
	};
	
	void completedAnimationSequenceNamed(const char *name) override {
	}
	
	void onNodeLoaded(cocos2d::Node* pNode, cocosbuilder::NodeLoader* pNodeLoader) override {
	}
}; // class SimpleView


/////////////////////////////
/////////////////////////////


class SimpleViewLoader
	: public cocosbuilder::NodeLoader {
public:
	static SimpleViewLoader* loader() {
		SimpleViewLoader* ptr = new SimpleViewLoader();
		if(ptr != nullptr) {
			ptr->autorelease();
			return ptr;
		}
		CC_SAFE_DELETE(ptr);
		return nullptr;
	}
	
protected:
	SimpleView* createNode(cocos2d::Node* pParent, cocosbuilder::CCBReader* ccbReader) {
		return SimpleView::create(pParent, ccbReader);
	}
}; // class SimpleViewLoader


#endif // __SimpleView_h__
