#include "ScenePause.h"
#include "SceneBattle.h"
#include "SceneCharacter.h"
#include "AppDelegate.h"


USING_NS_CC;

Scene *ScenePause::createScene() {
	Scene *scene = Scene::create();
	auto layer = ScenePause::create();
	scene->addChild(layer);
	return scene;
}

bool ScenePause::init() {
	if (!Scene::init()) {
		return false;
	}
	auto pauseBackground = Sprite::create("pauseBakground.jpg");
	pauseBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	pauseBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(pauseBackground);

	buttonContinue = Menu::create(MenuItemImage::create("continue.png", "continue1.png", this, menu_selector(ScenePause::buttonContinueClick)), NULL);
	buttonContinue->setPosition(designResolutionSize.width*0.4, designResolutionSize.height*0.5);
	this->addChild(buttonContinue);

	buttonToCharacter = Menu::create(MenuItemImage::create("exit.png", "exit1.png", this, menu_selector(ScenePause::buttonToCharacterClick)), NULL);
	buttonToCharacter->setPosition(designResolutionSize.width*0.6, designResolutionSize.height*0.5);
	this->addChild(buttonToCharacter);


	return true;
}
void ScenePause::buttonContinueClick(cocos2d::Object *sender) {
	auto sceneBattle = SceneBattle::create();
	Director::getInstance()->popScene();
}
void ScenePause::buttonToCharacterClick(cocos2d::Object *sender) {
	auto sceneCharacter = SceneCharacter::create();
	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(sceneCharacter);
}
