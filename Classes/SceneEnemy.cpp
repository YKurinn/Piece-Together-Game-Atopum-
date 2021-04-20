#include "SceneWeapon.h"
#include "SceneEnemy.h"
#include "SceneBattle.h"
#include "AppDelegate.h"
#include "Character.h"
#include "CharacterA.h"
#include "CharacterB.h"
#include "CharacterC.h"
#include "CharacterD.h"
#include "GlobalInstanceClass.h"


USING_NS_CC;

Scene *SceneEnemy::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneEnemy::create();
	scene->addChild(layer);
	return scene;
}

bool SceneEnemy::init() {
	if (!Scene::init()) {
		return false;
	}
	auto enemyBackground = Sprite::create("enemyBakground.jpg");
	enemyBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	enemyBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(enemyBackground);

	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneEnemy::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	buttonToBattle = Button::create("confirm.png", "confirm1.png", "confirm2.png");
	buttonToBattle->setPosition(Vec2(designResolutionSize.width*0.95, designResolutionSize.height*0.05));
	this->addChild(buttonToBattle);
	buttonToBattle->addClickEventListener([=](Ref *ref) {
		auto sceneBattle = SceneBattle::create();
		Director::getInstance()->replaceScene(sceneBattle);
	});
	buttonToBattle->setEnabled(false);

	buttonEnemyA = Button::create("tomoyo.png", "tomoyo.png", "tomoyo.png");
	buttonEnemyA->setPosition(Vec2(designResolutionSize.width*0.2, designResolutionSize.height*0.5));
	this->addChild(buttonEnemyA);
	buttonEnemyA->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::enemy = CharacterA::getChara();
		buttonToBattle->setEnabled(!(GlobalInstanceClass::enemy == GlobalInstanceClass::player));
	});
	buttonEnemyA->ignoreContentAdaptWithSize(false);
	buttonEnemyA->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.5));

	buttonEnemyB = Button::create("tomoyo.png", "tomoyo.png", "tomoyo.png");
	buttonEnemyB->setPosition(Vec2(designResolutionSize.width*0.4, designResolutionSize.height*0.5));
	this->addChild(buttonEnemyB);
	buttonEnemyB->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::enemy = CharacterB::getChara();
		buttonToBattle->setEnabled(!(GlobalInstanceClass::enemy == GlobalInstanceClass::player));
	});
	buttonEnemyB->ignoreContentAdaptWithSize(false);
	buttonEnemyB->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.5));


	buttonEnemyC = Button::create("tomoyo.png", "tomoyo.png", "tomoyo.png");
	buttonEnemyC->setPosition(Vec2(designResolutionSize.width*0.6, designResolutionSize.height*0.5));
	this->addChild(buttonEnemyC);
	buttonEnemyC->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::enemy = CharacterC::getChara();
		buttonToBattle->setEnabled(!(GlobalInstanceClass::enemy == GlobalInstanceClass::player));
	});
	buttonEnemyC->ignoreContentAdaptWithSize(false);
	buttonEnemyC->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.5));

	buttonEnemyD = Button::create("tomoyo.png", "tomoyo.png", "tomoyo.png");
	buttonEnemyD->setPosition(Vec2(designResolutionSize.width*0.8, designResolutionSize.height*0.5));
	this->addChild(buttonEnemyD);
	buttonEnemyD->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::enemy = CharacterD::getChara();
		buttonToBattle->setEnabled(!(GlobalInstanceClass::enemy == GlobalInstanceClass::player));
	});
	buttonEnemyD->ignoreContentAdaptWithSize(false);
	buttonEnemyD->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.5));
	return true;
}
void SceneEnemy::buttonBackClick(cocos2d::Object *sender) {
	auto sceneWeapon = SceneWeapon::create();
	Director::getInstance()->replaceScene(sceneWeapon);
}