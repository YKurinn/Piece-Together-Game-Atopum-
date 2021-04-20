#include "SceneSave.h"
#include "SceneMenu.h"
#include "AppDelegate.h"


USING_NS_CC;

Scene* SceneSave::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneSave::create();
	scene->addChild(layer);
	return scene;
}

bool SceneSave::init() {
	if (!Scene::init()) {
		return false;
	}
	auto settingBackground = Sprite::create("characterBakground.jpg");
	settingBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	this->addChild(settingBackground);

	return true;
}
