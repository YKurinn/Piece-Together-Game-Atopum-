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

	music = Label::createWithTTF("BGM:","fonts\\Marker Felt.ttf",40);
	music->setTextColor(Color4B::BLACK);
	music->setPosition((designResolutionSize.width) *0.3, 2 * (designResolutionSize.height) / 3);
	this->addChild(music);

	musicEffect = Label::createWithTTF("EFFECT:", "fonts\\Marker Felt.ttf", 40);
	musicEffect->setTextColor(Color4B::BLACK);
	musicEffect->setPosition((designResolutionSize.width) *0.3, designResolutionSize.height / 3);
	this->addChild(musicEffect);

	buttonMusic = Button::create();
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
		buttonMusic->loadTextureNormal("music1.png");
	}
	else {
		buttonMusic->loadTextureNormal("music0.png");
	}

	buttonMusic->setPosition(Vec2(2*(designResolutionSize.width )/ 5, 2*(designResolutionSize.height) / 3));
	buttonMusic->addClickEventListener([=](Ref* ref) {
		if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
			buttonMusic->loadTextureNormal("music0.png");
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			GlobalInstanceClass::music = false;
		}
		else {
			SimpleAudioEngine::getInstance()->playBackgroundMusic("03.mp3");
			buttonMusic->loadTextureNormal("music1.png");
			GlobalInstanceClass::music = true;
		}
	});
	this->addChild(buttonMusic);

	buttonMusicEffect = Button::create();

	if (GlobalInstanceClass::musicEffect) {
		buttonMusicEffect->loadTextureNormal("music1.png");
	}
	else buttonMusicEffect->loadTextureNormal("music0.png");

	buttonMusicEffect->setPosition(Vec2(2 * (designResolutionSize.width) / 5, (designResolutionSize.height) / 3));
	buttonMusicEffect->addClickEventListener([=](Ref* ref) {
		if (GlobalInstanceClass::musicEffect) {
			GlobalInstanceClass::musicEffect = false;
			buttonMusicEffect->loadTextureNormal("music0.png");
		}
		else {
			GlobalInstanceClass::musicEffect = true;
			buttonMusicEffect->loadTextureNormal("music1.png");
		}
	});
	this->addChild(buttonMusicEffect);



	return true;
}
void SceneSetting::buttonBackClick(cocos2d::Object *sender) {
	GlobalInstanceClass::playMusicEffect("audioButton1.wav");
	auto sceneMenu = SceneMenu::create();
	Director::getInstance()->replaceScene(sceneMenu);
}