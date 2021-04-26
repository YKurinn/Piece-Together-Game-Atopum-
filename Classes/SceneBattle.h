#ifndef __SCENE_BATTLE_H__
#define __SCENE_BATTLE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "AppDelegate.h"
#include "GlobalInstanceClass.h"
#include "SceneCharacter.h"
#include "SceneMenu.h"
#include "Shake.h"

USING_NS_CC;
using namespace cocos2d::ui;

class SceneBattle : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneBattle);

	Button* buttonPause;
	Button* buttonContinue;
	Button* buttonQuit;
	Sprite* pauseWindow;

	Sprite* battleSuccess;
	Button* buttonSuccess;

	Sprite* playerBloodBarBack;
	Sprite* playerBloodBar;
	Sprite* playerAngerBar;
	Sprite* enemyBloodBarBack;
	Sprite* enemyBloodBar;
	Sprite* enemyAngerBar;
	

	void playerAttack(float dt);

	void playerEndSpeedSkill(float dt);

	void enemyAttack(float dt);

	void enemyEndSpeedSkill(float dt);

	void playerEndSkill(float dt);

	void enemyEndSkill(float dt);
	
	void update(float dt);


};

#endif 