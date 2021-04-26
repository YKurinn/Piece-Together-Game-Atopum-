#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ui\CocosGUI.h"
#include "GlobalInstanceClass.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace CocosDenshion;

class SceneSetting : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	Menu *buttonBack;

	Label* music;

	Button* buttonMusic;

	Button* buttonMusicEffect;

	Label* musicEffect;

	void buttonBackClick(cocos2d::Object *Sender);

	CREATE_FUNC(SceneSetting);
};

#endif 