#ifndef __SCENE_WEAPON_H__
#define __SCENE_WEAPON_H__

#include "cocos2d.h"

USING_NS_CC;


class SceneWeapon : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneWeapon);

	Menu *buttonBack;

	Menu *buttonToEnemy;

	void buttonToEnemyClick(cocos2d::Object *Sender);

	void buttonBackClick(cocos2d::Object *Sender);
};

#endif 