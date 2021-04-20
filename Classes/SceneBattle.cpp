#include "ScenePause.h"
#include "SceneBattle.h"
#include "AppDelegate.h"
#include "GlobalInstanceClass.h"

USING_NS_CC;

Scene *SceneBattle::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneBattle::create();
	scene->addChild(layer);
	return scene;
}

bool SceneBattle::init() {
	if (!Scene::init()) {
		return false;
	}
	//添加两个战斗的角色
	GlobalInstanceClass::player->refresh();
	GlobalInstanceClass::enemy->refresh();
	this->addChild(GlobalInstanceClass::player);
	this->addChild(GlobalInstanceClass::enemy);
	

	//定时器
	this->scheduleUpdate();//每帧都会执行的定时器

	this->schedule(SEL_SCHEDULE(&SceneBattle::playerAttack),(float)( 1 / GlobalInstanceClass::player->currentSpeed));//玩家自动攻击定时器

	this->schedule(SEL_SCHEDULE(&SceneBattle::enemyAttack), (float)(1 / GlobalInstanceClass::enemy->currentSpeed));//玩家自动攻击定时器





	auto battleBackground = Sprite::create("battleBackground.jpg");
	battleBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	battleBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(battleBackground);

	buttonPause = Menu::create(MenuItemImage::create("pause.png", "pause1.png", this, menu_selector(SceneBattle::buttonPauseClick)), NULL);
	buttonPause->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonPause);

	return true;
}
void SceneBattle::buttonPauseClick(cocos2d::Object *sender) {
	auto scenePause = ScenePause::create();
	Director::getInstance()->pushScene(scenePause);
}

void SceneBattle::playerAttack(float dt) {
	GlobalInstanceClass::player->attack(GlobalInstanceClass::enemy);
}

void SceneBattle::enemyAttack(float dt) {
	GlobalInstanceClass::enemy->attack(GlobalInstanceClass::player);
}

void SceneBattle::playerEndSkill(float dt) {
	GlobalInstanceClass::player->endSkill();
}

void SceneBattle::enemyEndSkill(float dt) {
	GlobalInstanceClass::enemy->endSkill();
}

void SceneBattle::update(float dt) {
	if (GlobalInstanceClass::player->currentAnger == GlobalInstanceClass::player->maxAnger) {
		GlobalInstanceClass::player->runSkill();
		this->scheduleOnce(SEL_SCHEDULE(&SceneBattle::playerEndSkill), 5);
	}
	if (GlobalInstanceClass::enemy->currentAnger == GlobalInstanceClass::enemy->maxAnger) {
		GlobalInstanceClass::enemy->runSkill();
		this->scheduleOnce(SEL_SCHEDULE(&SceneBattle::enemyEndSkill), 5);
	}
	if (GlobalInstanceClass::player->currentHealth <= 0 || GlobalInstanceClass::enemy->currentHealth <= 0) {

	}
}