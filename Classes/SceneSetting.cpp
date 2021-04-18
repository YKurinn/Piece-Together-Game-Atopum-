#include "SceneSetting.h"
#include "SceneMenu.h"
#include "AppDelegate.h"


USING_NS_CC;

Scene* SceneSetting::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneSetting::create();
	scene->addChild(layer);
	return scene;
}

bool SceneSetting::init() {
	if (!Scene::init()) {
		return false;
	}
	auto settingBackground = Sprite::create("settingBakground.jpg");
	settingBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	settingBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(settingBackground);

	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneSetting::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	return true;
}
void SceneSetting::buttonBackClick(cocos2d::Object *sender) {
	auto sceneMenu = SceneMenu::create();
	Director::getInstance()->replaceScene(sceneMenu);
}