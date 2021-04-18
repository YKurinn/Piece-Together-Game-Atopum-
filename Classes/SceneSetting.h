#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;


class SceneSetting : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	Menu *buttonBack;

	void buttonBackClick(cocos2d::Object *Sender);

	CREATE_FUNC(SceneSetting);
};

#endif 