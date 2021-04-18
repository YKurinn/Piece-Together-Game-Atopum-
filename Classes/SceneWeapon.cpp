#include "SceneWeapon.h"
#include "SceneEnemy.h"
#include "SceneCharacter.h"
#include "AppDelegate.h"


USING_NS_CC;

Scene* SceneWeapon::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneWeapon::create();
	scene->addChild(layer);
	return scene;
}

bool SceneWeapon::init() {
	if (!Scene::init()) {
		return false;
	}
	auto weaponBackground = Sprite::create("weaponBakground.jpg");
	weaponBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	weaponBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(weaponBackground);

	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneWeapon::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	buttonToEnemy = Menu::create(MenuItemImage::create("continue.png", "continue1.png", this, menu_selector(SceneWeapon::buttonToEnemyClick)), NULL);
	buttonToEnemy->setPosition(designResolutionSize.width*0.95, designResolutionSize.height*0.05);
	this->addChild(buttonToEnemy);

	return true;
}
void SceneWeapon::buttonBackClick(cocos2d::Object *sender) {
	auto sceneCharacter = SceneCharacter::create();
	Director::getInstance()->replaceScene(sceneCharacter);
}
void SceneWeapon::buttonToEnemyClick(cocos2d::Object *sender) {
	auto sceneEnemy = SceneEnemy::create();
	Director::getInstance()->replaceScene(sceneEnemy);
}
