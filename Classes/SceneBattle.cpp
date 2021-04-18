#include "ScenePause.h"
#include "SceneBattle.h"
#include "AppDelegate.h"


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