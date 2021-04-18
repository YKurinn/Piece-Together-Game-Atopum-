#ifndef __SETU_SCENE_H__
#define __SETU_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;


class SceneSetu: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneSetu);

	Menu *buttonBack;

	void buttonBackClick(cocos2d::Object *Sender);
};

#endif 