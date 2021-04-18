#include "SceneWeapon.h"
#include "SceneEnemy.h"
#include "SceneBattle.h"
#include "AppDelegate.h"


USING_NS_CC;

Scene *SceneEnemy::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneEnemy::create();
	scene->addChild(layer);
	return scene;
}

bool SceneEnemy::init() {
	if (!Scene::init()) {
		return false;
	}
	auto enemyBackground = Sprite::create("enemyBakground.jpg");
	enemyBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	enemyBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(enemyBackground);

	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneEnemy::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	buttonToBattle = Menu::create(MenuItemImage::create("continue.png", "continue1.png", this, menu_selector(SceneEnemy::buttonToBattleClick)), NULL);
	buttonToBattle->setPosition(designResolutionSize.width*0.95, designResolutionSize.height*0.05);
	this->addChild(buttonToBattle);

	return true;
}
void SceneEnemy::buttonBackClick(cocos2d::Object *sender) {
	auto sceneWeapon = SceneWeapon::create();
	Director::getInstance()->replaceScene(sceneWeapon);
}
void SceneEnemy::buttonToBattleClick(cocos2d::Object *sender) {
	auto sceneBattle = SceneBattle::create();
	Director::getInstance()->replaceScene(sceneBattle);
}
