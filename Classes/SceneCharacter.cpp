#include "SceneCharacter.h"
#include "SceneMenu.h"
#include "AppDelegate.h"
#include "SceneWeapon.h"


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
	auto characterBackground = Sprite::create("characterBakground.jpg");
	characterBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	characterBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(characterBackground);

	buttonBack = Menu::create(MenuItemImage::create("back.png", "back1.png", this, menu_selector(SceneCharacter::buttonBackClick)), NULL);
	buttonBack->setPosition(designResolutionSize.width*0.05, designResolutionSize.height*0.95);
	this->addChild(buttonBack);

	buttonToWeapon = Menu::create(MenuItemImage::create("continue.png", "continue1.png", this, menu_selector(SceneCharacter::buttonToWeaponClick)), NULL);
	buttonToWeapon->setPosition(designResolutionSize.width*0.95, designResolutionSize.height*0.05);
	this->addChild(buttonToWeapon);

	return true;
}
void SceneCharacter::buttonBackClick(cocos2d::Object *sender) {
	auto sceneMenu = SceneMenu::create();
	Director::getInstance()->replaceScene(sceneMenu);
}
void SceneCharacter::buttonToWeaponClick(cocos2d::Object *sender) {
	auto sceneWeapon = SceneWeapon::create();
	Director::getInstance()->replaceScene(sceneWeapon);
}