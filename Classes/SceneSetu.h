#ifndef __SETU_SCENE_H__
#define __SETU_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;

class SceneSetu: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneSetu);

	Menu *buttonBack;

	void buttonBackClick(cocos2d::Object *Sender);

	Button* buttons[50];

	Sprite* selects[50];

	Sprite* setuBackground;

	int visibleNum = -1;
};

#endif 