#include "SceneInitialization.h"


USING_NS_CC;
using namespace CocosDenshion;

Scene* SceneInitialization::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneInitialization::create();
	scene->addChild(layer);
	return scene;
}
bool SceneInitialization::init() {
	if (!Scene::init()) {
		return false;
	}


	//切换到菜单界面
	this->scheduleOnce(schedule_selector(SceneInitialization::changeScene), 0.05f);

	//启动游戏时的初始化

		GlobalInstanceClass::isGameSaved = UserDefault::sharedUserDefault()->getBoolForKey("isGameSaved");
	if (!GlobalInstanceClass::isGameSaved) {
		GlobalInstanceClass::createAllGlobalInstance();
		GlobalInstanceClass::firstInitializeAll();
		GlobalInstanceClass::saveAll();
		UserDefault::sharedUserDefault()->setBoolForKey("musicEffect", true);
		UserDefault::sharedUserDefault()->setBoolForKey("music", true);
		UserDefault::sharedUserDefault()->setBoolForKey("isGameSaved", true);

	}
	GlobalInstanceClass::loadAll();
	//加载BGM
	GlobalInstanceClass::playMusic("03.mp3");

	return true;
}
void SceneInitialization::changeScene(float dt) {
	auto sceneMenu = SceneMenu::create();
	Director::getInstance()->replaceScene(sceneMenu);
}