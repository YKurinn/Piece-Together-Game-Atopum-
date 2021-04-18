#ifndef __SCENE_PAUSE_H__
#define __SCENE_PAUSE_H__

#include "cocos2d.h"

USING_NS_CC;


class ScenePause : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(ScenePause);

	Menu *buttonContinue;

	Menu *buttonToCharacter;

	void buttonContinueClick(cocos2d::Object *Sender);

	void buttonToCharacterClick(cocos2d::Object *Sender);
};

#endif 