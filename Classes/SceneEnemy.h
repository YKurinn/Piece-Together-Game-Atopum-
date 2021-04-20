#ifndef __SCENE_ENEMY_H__
#define __SCENE_ENEMY_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class SceneEnemy : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneEnemy);

	Menu *buttonBack;

	Button *buttonToBattle;

	Button *buttonEnemyA;

	Button *buttonEnemyB;

	Button *buttonEnemyC;

	Button *buttonEnemyD;

	void buttonToBattleClick(cocos2d::Object *Sender);

	void buttonBackClick(cocos2d::Object *Sender);
};

#endif 