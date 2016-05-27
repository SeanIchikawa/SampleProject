#include "SimpleView.h"


namespace {

cocos2d::Node* loadCCBI(std::string fileName) {
	cocosbuilder::CCBReader *ccbReader = new cocosbuilder::CCBReader(cocosbuilder::NodeLoaderLibrary::getInstance());
	cocos2d::Node* node = ccbReader->readNodeGraphFromFile(fileName.c_str());
	CC_SAFE_DELETE(ccbReader);
	return node;
}

} // namespace


/////////////////////////////
/////////////////////////////


SimpleView* SimpleView::create(cocos2d::Node* pParent, cocosbuilder::CCBReader* ccbReader) {
	auto ret = new (std::nothrow) SimpleView();
	if (ret && ret->init(pParent, ccbReader)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return ret;
}

SimpleView* SimpleView::createLayer() {
	auto ret = static_cast<SimpleView*>(::loadCCBI("simple.ccbi"));
	return ret;
}

SimpleView::SimpleView() {
}

SimpleView::~SimpleView() {
}

bool SimpleView::init(cocos2d::Node* parent, cocosbuilder::CCBReader* ccbReader) {
	if (!cocos2d::Node::init()) {
		return false;
	}
	
	if (parent) {
		setParent(parent);
	}

	return true;
}

cocos2d::SEL_MenuHandler SimpleView::onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName) {
	cocos2d::log("SimpleView::onResolveCCBCCMenuItemSelector(%d): start: name=%s", __LINE__, pSelectorName);
	
	CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onClick", SimpleView::onClick);
	
	cocos2d::log("SimpleView::onResolveCCBCCMenuItemSelector(%d): end: name=%s", __LINE__, pSelectorName);
	return nullptr;
}
