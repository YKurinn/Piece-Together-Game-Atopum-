#ifndef __INITIALIZATION_SCENE_H__
#define __INITIALIZATION_SCENE_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SceneMenu.h"
#include "AppDelegate.h"
#include "SimpleAudioEngine.h"
#include "GlobalInstanceClass.h"

USING_NS_CC;
using namespace cocos2d::ui;


class SceneInitialization : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void changeScene(float dt);

	CREATE_FUNC(SceneInitialization);
};

#endif 