#ifndef __SCENE_BATTLE_H__
#define __SCENE_BATTLE_H__

#include "cocos2d.h"

USING_NS_CC;


class SceneBattle : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneBattle);

	Menu *buttonPause;

	void buttonPauseClick(cocos2d::Object *Sender);
};

#endif 