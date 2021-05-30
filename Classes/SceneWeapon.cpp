#include "SceneWeapon.h"
#include "SceneEnemy.h"
#include "SceneCharacter.h"
#include "AppDelegate.h"
#include "GlobalInstanceClass.h"
#include "Weapon.h"
#include "Character.h"
#include "CharacterA.h"
#include "CharacterB.h"
#include "CharacterC.h"
#include "CharacterD.h"



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
	//初始化主角
	GlobalInstanceClass::player->refresh();

	

	//背景图片
	auto weaponBackground = Sprite::create("weaponBakground.jpg");
	weaponBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	weaponBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(weaponBackground);

	//info图片
	auto selectWeapon = Sprite::create("selectWeapon.png");
	selectWeapon->setPosition(designResolutionSize.width / 2, designResolutionSize.height * 0.8);
	this->addChild(selectWeapon);
	

	//返回按钮
	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneWeapon::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	//确定按钮
	buttonToEnemy = Menu::create(MenuItemImage::create("confirm.png", "confirm1.png", this, menu_selector(SceneWeapon::buttonToEnemyClick)), NULL);
	buttonToEnemy->setPosition(designResolutionSize.width*0.95, designResolutionSize.height*0.05);
	this->addChild(buttonToEnemy);

	//选择武器1
	buttonWeapon1 = Button::create("weapon1.png", "weapon1.png", "weapon1.png");
	buttonWeapon1->setPosition(Vec2(designResolutionSize.width*0.2, designResolutionSize.height*0.5));
	this->addChild(buttonWeapon1);
	buttonWeapon1->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::player->removeWeapon();
		GlobalInstanceClass::player->equipWeapon(Weapon::create("weapon1.png","cd",0.15,"damage"));
	});
	buttonWeapon1->ignoreContentAdaptWithSize(false);
	buttonWeapon1->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.width * 0.15));
	//武器说明
	Label* weaponLabel1 = Label::createWithTTF("WindViolenceBigSword", "fonts\\Marker Felt.ttf", 30);
	Label* weaponLabel2 = Label::createWithTTF("Increase your damage", "fonts\\Marker Felt.ttf", 30);
	weaponLabel1->setPosition(Vec2(designResolutionSize.width * 0.2, designResolutionSize.height * 0.5-100));
	weaponLabel2->setPosition(Vec2(designResolutionSize.width * 0.2, designResolutionSize.height * 0.5-200));
	this->addChild(weaponLabel1);
	this->addChild(weaponLabel2);

	//选择武器2
	buttonWeapon2 = Button::create("weapon2.png", "weapon2.png", "weapon2.png");
	buttonWeapon2->setPosition(Vec2(designResolutionSize.width*0.4, designResolutionSize.height*0.5));
	this->addChild(buttonWeapon2);
	buttonWeapon2->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::player->removeWeapon();
		GlobalInstanceClass::player->equipWeapon(Weapon::create("weapon1.png", "cd", 0.15, "defence"));
	});
	buttonWeapon2->ignoreContentAdaptWithSize(false);
	buttonWeapon2->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.width * 0.15));
	//武器说明
	Label* weaponLabel3 = Label::createWithTTF("LockSonArmor", "fonts\\Marker Felt.ttf", 30);
	Label* weaponLabel4 = Label::createWithTTF("Increase your defence", "fonts\\Marker Felt.ttf", 30);
	weaponLabel3->setPosition(Vec2(designResolutionSize.width * 0.4, designResolutionSize.height * 0.5 - 100));
	weaponLabel4->setPosition(Vec2(designResolutionSize.width * 0.4, designResolutionSize.height * 0.5 - 200));
	this->addChild(weaponLabel3);
	this->addChild(weaponLabel4);

	//选择武器3
	buttonWeapon3 = Button::create("weapon3.png", "weapon3.png", "weapon3.png");
	buttonWeapon3->setPosition(Vec2(designResolutionSize.width*0.6, designResolutionSize.height*0.5));
	this->addChild(buttonWeapon3);
	buttonWeapon3->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::player->removeWeapon();
		GlobalInstanceClass::player->equipWeapon(Weapon::create("weapon1.png", "cd", 0.15, "health"));
	});
	buttonWeapon3->ignoreContentAdaptWithSize(false);
	buttonWeapon3->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.width * 0.15));
	//武器说明
	Label* weaponLabel5 = Label::createWithTTF("HugeManWaistMelt", "fonts\\Marker Felt.ttf", 30);
	Label* weaponLabel6 = Label::createWithTTF("Increase your health", "fonts\\Marker Felt.ttf", 30);
	weaponLabel5->setPosition(Vec2(designResolutionSize.width * 0.6, designResolutionSize.height * 0.5 - 100));
	weaponLabel6->setPosition(Vec2(designResolutionSize.width * 0.6, designResolutionSize.height * 0.5 - 200));
	this->addChild(weaponLabel5);
	this->addChild(weaponLabel6);

	//选择武器4
	buttonWeapon4 = Button::create("weapon4.png", "weapon4.png", "weapon4.png");
	buttonWeapon4->setPosition(Vec2(designResolutionSize.width*0.8, designResolutionSize.height*0.5));
	this->addChild(buttonWeapon4);
	buttonWeapon4->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::player->removeWeapon();
		GlobalInstanceClass::player->equipWeapon(Weapon::create("weapon1.png", "cd", 0.05, "speed"));
	});
	buttonWeapon4->ignoreContentAdaptWithSize(false);
	buttonWeapon4->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.width * 0.15));
	//武器说明
	Label* weaponLabel7 = Label::createWithTTF("AntiCurved'sBow", "fonts\\Marker Felt.ttf", 30);
	Label* weaponLabel8 = Label::createWithTTF("Increase your speed", "fonts\\Marker Felt.ttf", 30);
	weaponLabel7->setPosition(Vec2(designResolutionSize.width * 0.8, designResolutionSize.height * 0.5 - 100));
	weaponLabel8->setPosition(Vec2(designResolutionSize.width * 0.8, designResolutionSize.height * 0.5 - 200));
	this->addChild(weaponLabel7);
	this->addChild(weaponLabel8);

	return true;
}

//返回按钮点击事件
void SceneWeapon::buttonBackClick(cocos2d::Object *sender) {
	GlobalInstanceClass::playMusicEffect("audioButton1.wav");
	auto sceneCharacter = SceneCharacter::create();
	Director::getInstance()->replaceScene(sceneCharacter);
}

//确定按钮点击事件
void SceneWeapon::buttonToEnemyClick(cocos2d::Object *sender) {
	GlobalInstanceClass::playMusicEffect("audioButton1.wav");
	auto sceneEnemy = SceneEnemy::create();
	Director::getInstance()->replaceScene(sceneEnemy);
}
