#include "ScalableMenuItemImage.h"
//#include "../../common/util/CommonUtility.h"


/**
 * デストラクタ.
 */
ScalableMenuItemImage::~ScalableMenuItemImage()
{

}

/**
 * インスタンス生成
 */
ScalableMenuItemImage * ScalableMenuItemImage::create()
{
	ScalableMenuItemImage * pRet = new ScalableMenuItemImage();
	
	if (pRet && pRet->init()) {
		pRet->autorelease();
	} else {
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

ScalableMenuItemImage* ScalableMenuItemImage::create(const std::string& normalImage, const std::string& selectedImage)
{
	return ScalableMenuItemImage::create(normalImage, selectedImage, ""/*disabledImage*/, (const cocos2d::ccMenuCallback&)nullptr);
}

ScalableMenuItemImage* ScalableMenuItemImage::create(const std::string& normalImage, const std::string& selectedImage, const cocos2d::ccMenuCallback& callback)
{
	return ScalableMenuItemImage::create(normalImage, selectedImage, ""/*disabledImage*/, callback);
}

ScalableMenuItemImage* ScalableMenuItemImage::create(const std::string& normalImage, const std::string& selectedImage, const std::string& disabledImage, const cocos2d::ccMenuCallback& callback)
{
	ScalableMenuItemImage * pRet = new ScalableMenuItemImage();
	// memo:引数なしのcreate()から呼び出されているinit()から呼び出されるsetCascadeOpacityEnabled(true);は、
	//      initWithNormalImage()>initWithNormalSprite()の中で呼び出されている。
	if (pRet && pRet->initWithNormalImage(normalImage, selectedImage, disabledImage, callback)) {
		pRet->autorelease();
	} else {
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

/**
 * 初期化
 */
bool ScalableMenuItemImage::init()
{
	setCascadeOpacityEnabled(true);

	m_applyScaleToOtherChild = false;

	m_onSelected = nullptr;

	m_applyScale = true;
	
	return MenuItemImage::init();
}

/**
 * 選択された時に呼び出される
 */
void ScalableMenuItemImage::selected()
{
	MenuItem::selected();
	// 選択時callbackがセットされていれば呼び出し.
	if(m_onSelected){
		m_onSelected(true);
	}
	
	if (_enabled) {
		if (_normalImage) {
			cocos2d::Size size = _normalImage->getContentSize();
			_normalImage->setAnchorPoint(cocos2d::Point(0.5f, 0.5f));
			_normalImage->setPosition(cocos2d::Point(size.width/2, size.height/2));
			if (m_applyScale) {
				_normalImage->setScale(1.10f);
				applyScaleToOtherChild(1.10f);
			}
		}
	}
}

/**
 * 選択から外れた時に呼び出される
 */
void ScalableMenuItemImage::unselected()
{
	MenuItem::unselected();
	// 選択時callbackがセットされていれば呼び出し.
	if(m_onSelected){
		m_onSelected(false);
	}
	
	if (_enabled) {
		if (_normalImage && m_applyScale) {
			_normalImage->setScale(1.00f);
			applyScaleToOtherChild(1.00f);
		}
	}
}
/**
 * フェードイン
 */
void ScalableMenuItemImage::fadeIn(float sec)
{
	if (_visible) {
		runAction(cocos2d::FadeIn::create(sec));
	}
}

/**
 * フェードアウト
 */
void ScalableMenuItemImage::fadeOut(float sec)
{
	if (_visible) {
		runAction(cocos2d::FadeOut::create(sec));
	}
}

/** 3種のボタン以外の子オブジェクトのスケールを変更する. */
void ScalableMenuItemImage::applyScaleToOtherChild(float scale)
{
	// 機能が有効でないなら何もしない.
	if (m_applyScaleToOtherChild == false) {
		return;
	}

	// 3種のボタン以外の子オブジェクトのスケールを変更する.
	const cocos2d::Vector<cocos2d::Node*>& children = this->getChildren();
	for (cocos2d::Node* node : children) {
		// 3種のボタンなら何もしない.
		if (node == this->getNormalImage() ||
			node == this->getSelectedImage() ||
			node == this->getDisabledImage()) {
			continue;
		}
		node->setScale(scale);
	}
}