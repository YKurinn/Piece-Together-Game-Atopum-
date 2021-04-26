#include "SceneSetu.h"
#include "SceneMenu.h"
#include "AppDelegate.h"
#include "GlobalInstanceClass.h"


USING_NS_CC;

Scene* SceneSetu::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneSetu::create();
	scene->addChild(layer);
	return scene;
}

bool SceneSetu::init() {
	if (!Scene::init()) {
		return false;
	}
	auto setuBackground = Sprite::create("setuBakground.jpg");
	setuBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	setuBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(setuBackground);

	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneSetu::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	return true;
}
void SceneSetu::buttonBackClick(cocos2d::Object *sender) {
	GlobalInstanceClass::playMusicEffect("audioButton1.wav");
	auto sceneMenu = SceneMenu::create();
	Director::getInstance()->replaceScene(sceneMenu);
}