#ifndef __SCENE_WEAPON_H__
#define __SCENE_WEAPON_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;

class SceneWeapon : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneWeapon);

	Menu *buttonBack;

	Menu *buttonToEnemy;

	Button *buttonWeapon1;

	Button *buttonWeapon2;

	Button *buttonWeapon3;

	Button *buttonWeapon4;

	void buttonToEnemyClick(cocos2d::Object *Sender);

	void buttonBackClick(cocos2d::Object *Sender);
};

#endif 