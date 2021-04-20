#ifndef __SAVE_SCENE_H__
#define __SAVE_SCENE_H__

#include "cocos2d.h"


class SceneSave : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneSave);
};

#endif 