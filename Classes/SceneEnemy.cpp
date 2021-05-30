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

	//背景图片
	auto enemyBackground = Sprite::create("enemyBakground.jpg");
	enemyBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	enemyBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(enemyBackground);

	//返回按钮
	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneEnemy::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	//确定按钮
	buttonToBattle = Button::create("confirm.png", "confirm1.png", "confirm2.png");
	buttonToBattle->setPosition(Vec2(designResolutionSize.width*0.95, designResolutionSize.height*0.05));
	this->addChild(buttonToBattle);
	buttonToBattle->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		enemyChooes->setVisible(true);
		enemyLevel0->setEnabled(true);
		enemyLevel30->setEnabled(true);
		enemyLevel50->setEnabled(true);
		enemyensure->setEnabled(true);
		enemyLevel0->setVisible(true);
		enemyLevel30->setVisible(true);
		enemyLevel50->setVisible(true);
		enemyensure->setVisible(true);
	});
	buttonToBattle->setEnabled(false);

	//选难度
	enemyChooes = Sprite::create("enemyChooes.png");
	enemyChooes->setPosition(designResolutionSize.width*0.5, designResolutionSize.height*0.5);
	enemyChooes->setContentSize(Size(400, 300));
	enemyChooes->setVisible(false);
	this->addChild(enemyChooes, 1);

	enemyLevel0 = Button::create("enemyLevel0.png", "enemyLevel0.png");
	enemyChooes->addChild(enemyLevel0);
	enemyLevel0->setPosition(Vec2(100, 150));
	enemyLevel0->setContentSize(Size(30, 30));
	enemyLevel0->setVisible(false);
	enemyLevel0->setEnabled(false);
	enemyLevel0->addClickEventListener([=](Ref* ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::enemy->level = 0;
		enemyensure->setEnabled(true);
	});


	enemyLevel30 = Button::create("enemyLevel30.png", "enemyLevel30.png");
	enemyLevel30->setPosition(Vec2(200, 150));
	enemyLevel30->setVisible(false);
	enemyLevel30->setEnabled(false);
	enemyLevel30->setContentSize(Size(30, 100));
	enemyLevel30->addClickEventListener([=](Ref* ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::enemy->level = 30;
		enemyensure->setEnabled(true);
	});
	enemyChooes->addChild(enemyLevel30);

	enemyLevel50 = Button::create("enemyLevel50.png", "enemyLevel50.png");
	enemyLevel50->setPosition(Vec2(300, 150));
	enemyLevel50->setVisible(false);
	enemyLevel50->setEnabled(false);
	enemyLevel50->setContentSize(Size(30, 100));
	enemyLevel50->addClickEventListener([=](Ref* ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::enemy->level = 50;
		enemyensure->setEnabled(true);
	});
	enemyChooes->addChild(enemyLevel50);

	enemyensure = Button::create("confirm.png", "confirm1.png");
	enemyensure->setPosition(Vec2(200, 50));
	enemyensure->setVisible(false);
	enemyensure->setEnabled(false);
	enemyensure->addClickEventListener([=](Ref* ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		auto sceneBattle = SceneBattle::create();
		Director::getInstance()->replaceScene(sceneBattle);
	});
	enemyChooes->addChild(enemyensure);

	
	//选择敌人A
	buttonEnemyA = Button::create("tomoyo.png", "tomoyo.png", "tomoyo.png");
	buttonEnemyA->setPosition(Vec2(designResolutionSize.width*0.2, designResolutionSize.height*0.5));
	this->addChild(buttonEnemyA);
	buttonEnemyA->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::enemy = CharacterA::create("charaA_enemy.png");
		buttonToBattle->setEnabled(!(GlobalInstanceClass::enemy->name == GlobalInstanceClass::player->name));
	});
	buttonEnemyA->ignoreContentAdaptWithSize(false);
	buttonEnemyA->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.3));

	//选择敌人B
	buttonEnemyB = Button::create("sikadi.png", "sikadi.png", "sikadi.png");
	buttonEnemyB->setPosition(Vec2(designResolutionSize.width*0.4, designResolutionSize.height*0.5));
	this->addChild(buttonEnemyB);
	buttonEnemyB->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::enemy = CharacterB::create("charaB_enemy.png");
		buttonToBattle->setEnabled(!(GlobalInstanceClass::enemy->name == GlobalInstanceClass::player->name));
	});
	buttonEnemyB->ignoreContentAdaptWithSize(false);
	buttonEnemyB->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.3));

	//选择敌人C
	buttonEnemyC = Button::create("w.png", "w.png", "w.png");
	buttonEnemyC->setPosition(Vec2(designResolutionSize.width*0.6, designResolutionSize.height*0.5));
	this->addChild(buttonEnemyC);
	buttonEnemyC->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::enemy = CharacterC::create("charaC_enemy.png");
		buttonToBattle->setEnabled(!(GlobalInstanceClass::enemy->name == GlobalInstanceClass::player->name));
	});
	buttonEnemyC->ignoreContentAdaptWithSize(false);
	buttonEnemyC->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.3));

	//选择敌人D
	buttonEnemyD = Button::create("tiansuo.png", "tiansuo.png", "tiansuo.png");
	buttonEnemyD->setPosition(Vec2(designResolutionSize.width*0.8, designResolutionSize.height*0.5));
	this->addChild(buttonEnemyD);
	buttonEnemyD->addClickEventListener([=](Ref *ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		GlobalInstanceClass::enemy = CharacterD::create("charaD_enemy.png");
		buttonToBattle->setEnabled(!(GlobalInstanceClass::enemy->name == GlobalInstanceClass::player->name));
	});
	buttonEnemyD->ignoreContentAdaptWithSize(false);
	buttonEnemyD->setContentSize(Size(designResolutionSize.width*0.15, designResolutionSize.height*0.3));


	return true;
}

//返回按钮点击事件
void SceneEnemy::buttonBackClick(cocos2d::Object *sender) {
	GlobalInstanceClass::playMusicEffect("audioButton1.wav");
	auto sceneWeapon = SceneWeapon::create();
	Director::getInstance()->replaceScene(sceneWeapon);
}