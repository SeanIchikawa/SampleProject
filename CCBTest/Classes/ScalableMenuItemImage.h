#ifndef __ScalableMenuItemImage_h__
#define __ScalableMenuItemImage_h__

#include "cocos2d.h"

/* Forward declaration. */
class CCBReader;

/**
 * 
 */
class ScalableMenuItemImage : public cocos2d::MenuItemImage
{
public:
	/** デストラクタ */
	virtual ~ScalableMenuItemImage();
	
	/**
	 * インスタンス生成
	 */
	static ScalableMenuItemImage* create();

	/**
	 * インスタンス生成。同引数のMenuItemImage::create()に準ずる.
	 * @param	normalImage		通常状態の画像名
	 * @param	selectedImage	押下時の画像名
	 */
	static ScalableMenuItemImage* create(const std::string& normalImage, const std::string& selectedImage);

	/**
	 * インスタンス生成。同引数のMenuItemImage::create()に準ずる.
	 * @param	normalImage		通常状態の画像名
	 * @param	selectedImage	押下時の画像名
	 * @param	callback		クリック時のcallback
	 */
	static ScalableMenuItemImage* create(const std::string& normalImage, const std::string& selectedImage, const cocos2d::ccMenuCallback& callback);

	/**
	 * インスタンス生成。同引数のMenuItemImage::create()に準ずる.
	 * @param	normalImage		通常状態の画像名
	 * @param	selectedImage	押下時の画像名
	 * @param	disabledImage	無効化時の画像名
	 * @param	callback		クリック時のcallback
	 */
	static ScalableMenuItemImage* create(const std::string& normalImage, const std::string& selectedImage, const std::string& disabledImage, const cocos2d::ccMenuCallback& callback);
	
	/**
	 * フェードイン
	 */
	void fadeIn(float sec);
	
	/**
	 * フェードアウト
	 */
	void fadeOut(float sec);

	/** 拡縮を適用する機能を有効にする */
	void setEnableApplyScale(bool enable) { m_applyScale = enable; }

	/** 3種のボタン以外の子オブジェクトに、拡縮を適用する機能を有効にする */
	void inline enableApplyScaleToOtherChild(){ m_applyScaleToOtherChild = true; }
	
	/** 選択or選択解除時callbackの設定. */
	void setOnSelected(std::function<void(bool)> val){ m_onSelected = val; }
	
	/**
	 * 選択された時に呼び出される
	 */
	virtual void selected();
	/**
	 * 選択から外れた時に呼び出される
	 */
	virtual void unselected();

private:
	/** 拡縮を適用する機能を使用するかのフラグ */
	bool m_applyScale;

	/** 3種のボタン以外の子オブジェクトに、拡縮を適用する機能を使用するかのフラグ。m_applyScaleがtrueのときしか値は使われない。 */
	bool m_applyScaleToOtherChild;

protected:
	/** コンストラクタ */
	ScalableMenuItemImage() {}
	
	/** 選択or選択解除時callback. */
	std::function<void(bool)> m_onSelected;
	
	/**
	 * 初期化
	 */
	virtual bool init();

	/** 
	 * 3種のボタン以外の子オブジェクトに、拡縮を適用する
	 * @param	scale	スケール
	 */
	void applyScaleToOtherChild(float scale);
};

#endif //__ScalableMenuItemImage_h__
