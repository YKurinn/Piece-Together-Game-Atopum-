#include "SceneMenu.h"
#include "SceneCharacter.h"
#include "AppDelegate.h"
#include "SceneSetting.h"
#include "SceneSetu.h"
#include "GlobalInstanceClass.h"
#include "CharacterA.h"
#include "stdio.h"

USING_NS_CC;

Scene* SceneMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = SceneMenu::create();
	scene->addChild(layer);
    return scene;
}

bool SceneMenu::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	//启动游戏时的初始化
	GlobalInstanceClass::loadAll();
	GlobalInstanceClass::isGameSaved = UserDefault::sharedUserDefault()->getBoolForKey("isGameSaved");
	if(!GlobalInstanceClass::isGameSaved){
		GlobalInstanceClass::createAllGlobalInstance();
		GlobalInstanceClass::firstInitializeAll();
		GlobalInstanceClass::saveAll();
		UserDefault::sharedUserDefault()->setBoolForKey("isGameSaved", true);
	}


	//背景
	auto background = Sprite::create("sceneMenuBackground.jpg");
	background->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	background->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(background);


	//一堆UI按钮
	buttonStart = Menu::create(MenuItemImage::create("start.png", "start1.png", this, menu_selector(SceneMenu::buttonStartClick)), NULL);
	buttonSetting = Menu::create(MenuItemImage::create("setting.png", "setting1.png", this, menu_selector(SceneMenu::buttonSettingClick)), NULL);
	buttonSetu = Menu::create(MenuItemImage::create("setu.png", "setu1.png", this, menu_selector(SceneMenu::buttonSetuClick)), NULL);
	buttonSave = Menu::create(MenuItemImage::create("save.png", "save1.png", this, menu_selector(SceneMenu::buttonSaveClick)), NULL);
	buttonExit = Menu::create(MenuItemImage::create("exit.png", "exit1.png", this, menu_selector(SceneMenu::buttonExitClick)), NULL);
	buttonStart->setPosition(designResolutionSize.width/2, designResolutionSize.height*0.6);
	buttonSetting->setPosition(designResolutionSize.width / 2, designResolutionSize.height*0.5);
	buttonSetu->setPosition(designResolutionSize.width / 2, designResolutionSize.height*0.4);
	buttonSave->setPosition(designResolutionSize.width / 2, designResolutionSize.height*0.3);
	buttonExit->setPosition(designResolutionSize.width / 2, designResolutionSize.height*0.2);
	this->addChild(buttonStart);
	this->addChild(buttonSetting);
	this->addChild(buttonSetu);
	this->addChild(buttonSave);
	this->addChild(buttonExit);

	//存档成功按钮及标签
	saveSuccessButton = Button::create("confirm.png", "confirm.png", "confirm.png");
	saveSuccessButton->setVisible(false);
	saveSuccessButton->setEnabled(false);
	saveSuccessButton->setPosition(Vec2(800,700));
	saveSuccessButton->addClickEventListener([=](Ref* ref) {
		saveSuccessButton->setVisible(false);
		saveSuccessButton->setEnabled(false);
		saveSuccessLabel->setVisible(false);
	}
	);
	saveSuccessLabel = Label::createWithTTF("Saving success!", "fonts\\Marker Felt.ttf", 40);
	saveSuccessLabel->setPosition(Vec2(800, 800));
	saveSuccessLabel->setVisible(false);
	this->addChild(saveSuccessButton, 2);
	this->addChild(saveSuccessLabel, 2);

	return true;
}
void SceneMenu::buttonStartClick(cocos2d::Object *Sender) {
	auto *sceneCharacter = SceneCharacter::create();
	Director::getInstance()->replaceScene(sceneCharacter);
}

void SceneMenu::buttonSettingClick(cocos2d::Object *Sender) {
	auto *sceneSetting = SceneSetting::create();
	Director::getInstance()->replaceScene(sceneSetting);
}

void SceneMenu::buttonSaveClick(cocos2d::Object *Sender) {
	//存档方法
	if(GlobalInstanceClass::saveAll());
	saveSuccessButton->setVisible(true);
	saveSuccessButton->setEnabled(true);
	saveSuccessLabel->setVisible(true);
}

void SceneMenu::buttonSetuClick(cocos2d::Object *Sender) {
	auto *sceneSetu = SceneSetu::create();
	Director::getInstance()->replaceScene(sceneSetu);
}

void SceneMenu::buttonExitClick(cocos2d::Object* Sender) {
	//退出方法
	Director::getInstance()->end();
}