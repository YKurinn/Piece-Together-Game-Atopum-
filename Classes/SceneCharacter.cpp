#include "SceneCharacter.h"
#include "SceneMenu.h"
#include "AppDelegate.h"
#include "SceneWeapon.h"
#include "GlobalInstanceClass.h"


USING_NS_CC;

Scene* SceneCharacter::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneCharacter::create();
	scene->addChild(layer);
	return scene;
}

bool SceneCharacter::init() {
	if ( !Scene::init() ) {
		return false;
	}
	//背景图片

	auto characterBackground = Sprite::create("characterBakground.jpg");
	characterBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	characterBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(characterBackground);

	//返回按钮
	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneCharacter::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	//确定按钮
	buttonToWeapon = Button::create("confirm.png","confirm1.png","confirm2.png");
	buttonToWeapon->setPosition(Vec2(designResolutionSize.width*0.95, designResolutionSize.height*0.05));
	this->addChild(buttonToWeapon);
	buttonToWeapon->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		auto sceneWeapon = SceneWeapon::create();
		Director::getInstance()->replaceScene(sceneWeapon);
		
	});
	buttonToWeapon->setEnabled(false);

	//选择角色A
	buttonCharacterA = Button::create("tomoyo.png","tomoyo.png","tomoyo.png");
	buttonCharacterA->setPosition(Vec2(designResolutionSize.width*0.2, designResolutionSize.height*0.5));
	this->addChild(buttonCharacterA);
	buttonCharacterA->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::player = CharacterA::getChara();
		buttonToWeapon->setEnabled(CharacterA::getChara()->ownership);
	});
	buttonCharacterA->ignoreContentAdaptWithSize(false);
	buttonCharacterA->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.3));

	//选择角色B
	buttonCharacterB = Button::create("sikadi.png", "sikadi.png", "sikadi.png");
	buttonCharacterB->setPosition(Vec2(designResolutionSize.width*0.4, designResolutionSize.height*0.5));
	this->addChild(buttonCharacterB);
	buttonCharacterB->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::player = CharacterB::getChara();
		buttonToWeapon->setEnabled(CharacterB::getChara()->ownership);
	});
	buttonCharacterB->ignoreContentAdaptWithSize(false);
	buttonCharacterB->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.3));

	//选择角色C
	buttonCharacterC = Button::create("w.png", "w.png", "w.png");
	buttonCharacterC->setPosition(Vec2(designResolutionSize.width*0.6, designResolutionSize.height*0.5));
	this->addChild(buttonCharacterC);
	buttonCharacterC->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::player = CharacterC::getChara();
		buttonToWeapon->setEnabled(CharacterC::getChara()->ownership);
	});
	buttonCharacterC->ignoreContentAdaptWithSize(false);
	buttonCharacterC->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.3));

	//选择角色D
	buttonCharacterD = Button::create("tomoyo.png", "tomoyo.png", "tomoyo.png");
	buttonCharacterD->setPosition(Vec2(designResolutionSize.width*0.8, designResolutionSize.height*0.5));
	this->addChild(buttonCharacterD);
	buttonCharacterD->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::player = CharacterD::getChara();
		buttonToWeapon->setEnabled(CharacterD::getChara()->ownership);
	});
	buttonCharacterD->ignoreContentAdaptWithSize(false);
	buttonCharacterD->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.3));

	return true;
}

void SceneCharacter::buttonBackClick(cocos2d::Object *sender) {
	GlobalInstanceClass::playMusicEffect("audioButton1.wav");
	auto sceneMenu = SceneMenu::create();
	Director::getInstance()->replaceScene(sceneMenu);
}