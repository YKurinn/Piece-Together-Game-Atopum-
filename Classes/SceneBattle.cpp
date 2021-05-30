#include "SceneBattle.h"
USING_NS_CC;

#define BLDBW 600
#define BLDBH 50


Scene *SceneBattle::createScene() {
	Scene *scene = Scene::create();
	auto layer = SceneBattle::create();
	scene->addChild(layer);
	return scene;
}

bool SceneBattle::init() {
	if (!Scene::init()) {
		return false;
	}

	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	GlobalInstanceClass::playMusic("04.mp3");


	//添加两个战斗的角色
	this->addChild(GlobalInstanceClass::player,0);
	this->addChild(GlobalInstanceClass::enemy,0);
	GlobalInstanceClass::player->setPosition(Vec2(designResolutionSize.width * 0.3, designResolutionSize.height * 0.4));
	GlobalInstanceClass::enemy->setPosition(Vec2(designResolutionSize.width * 0.7, designResolutionSize.height * 0.4));
	//初始化敌人
	GlobalInstanceClass::enemy->refresh();
	//血条和怒气条
	playerBloodBarBack = Sprite::create("bloodBarBack.png");
	playerBloodBar = Sprite::create("bloodBar.png");
	playerAngerBar = Sprite::create("angerBar.png");
	playerBloodBarBack->addChild(playerBloodBar);
	playerBloodBarBack->addChild(playerAngerBar);
	playerBloodBar->setPosition(0, BLDBH/2);
	playerAngerBar->setPosition(0, 0);
	playerBloodBarBack->setContentSize(Size(BLDBW,BLDBH));
	playerBloodBar->setContentSize(Size(BLDBW, BLDBH / 2));
	playerAngerBar->setContentSize(Size(BLDBW, BLDBH / 2));
	playerBloodBar->setAnchorPoint(Vec2(0, 0));
	playerAngerBar->setAnchorPoint(Vec2(0, 0));
	playerBloodBarBack->setAnchorPoint(Vec2(0, 0));

	enemyBloodBarBack = Sprite::create("bloodBarBack.png");
	enemyBloodBar = Sprite::create("bloodBar.png");
	enemyAngerBar = Sprite::create("angerBar.png");
	enemyBloodBarBack->addChild(enemyBloodBar);
	enemyBloodBarBack->addChild(enemyAngerBar);
	enemyBloodBar->setPosition(0, BLDBH/2);
	enemyAngerBar->setPosition(0, 0);
	enemyBloodBarBack->setContentSize(Size(BLDBW, BLDBH));
	enemyBloodBar->setContentSize(Size(BLDBW, BLDBH / 2));
	enemyAngerBar->setContentSize(Size(BLDBW, BLDBH / 2));
	enemyBloodBar->setAnchorPoint(Vec2(0, 0));
	enemyAngerBar->setAnchorPoint(Vec2(0, 0));
	enemyBloodBarBack->setAnchorPoint(Vec2(0, 0));
	
	this->addChild(playerBloodBarBack, 0);
	this->addChild(enemyBloodBarBack, 0);
	playerBloodBarBack->setPosition(100,700);
	enemyBloodBarBack->setPosition(900, 700);


	//定时器
	this->scheduleUpdate();//每帧都会执行的定时器

	this->schedule(SEL_SCHEDULE(&SceneBattle::playerAttack),(float)( 1 / GlobalInstanceClass::player->basicSpeed));//玩家自动攻击定时器

	this->schedule(SEL_SCHEDULE(&SceneBattle::enemyAttack), (float)(1 / GlobalInstanceClass::enemy->basicSpeed));//敌人自动攻击定时器

	//背景图片
	auto battleBackground = Sprite::create("battleBack.png");
	battleBackground->setPosition(designResolutionSize.width / 2, designResolutionSize.height / 2);
	battleBackground->setContentSize(Size(designResolutionSize.width, designResolutionSize.height));
	this->addChild(battleBackground,-1);

	//暂停按钮
	buttonPause = Button::create("pause.png", "pause1.png");
	buttonPause->setPosition(Vec2(designResolutionSize.width*0.05, designResolutionSize.height*0.95));
	buttonPause->addClickEventListener([=](Ref* ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		Director::sharedDirector()->pause();
		pauseWindow->setVisible(true);
		buttonContinue->setEnabled(true);
		buttonQuit->setEnabled(true);
	});
	this->addChild(buttonPause,0);

	//暂停窗口
	pauseWindow = Sprite::create("pauseWindow.png");
	pauseWindow->setPosition(designResolutionSize.width*0.5, designResolutionSize.height*0.5);
	pauseWindow->setContentSize(Size(400, 300));
	pauseWindow->setVisible(false);
	//继续按钮
	buttonContinue = Button::create("continueBattle.png", "continueBattle1.png");
	buttonContinue->setEnabled(false);
	//退出按钮
	buttonQuit = Button::create("quitBattle.png", "quitBattle1.png");
	buttonQuit->setEnabled(false);
	//窗口与按钮的位置处理
	pauseWindow->addChild(buttonContinue);
	pauseWindow->addChild(buttonQuit);
	buttonContinue->setPosition(Vec2(200,180));
	buttonQuit->setPosition(Vec2(200, 80));
	//继续按钮点击事件
	buttonContinue->addClickEventListener([=](Ref* ref) {
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		Director::sharedDirector()->resume();
		pauseWindow->setVisible(false);
		buttonContinue->setEnabled(false);
		buttonQuit->setEnabled(false);
	});
	//退出按钮点击事件
	buttonQuit->addClickEventListener([=](Ref* ref) {
		Director::sharedDirector()->resume();
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		GlobalInstanceClass::playMusic("03.mp3");
		GlobalInstanceClass::playMusicEffect("audioButton1.wav");
		Scene* scene = SceneCharacter::create();
		Director::sharedDirector()->replaceScene(scene);

	});
	this->addChild(pauseWindow,1);

	//胜利窗口
	battleSuccess = Sprite::create("battleSuccess.png");
	battleSuccess->setPosition(designResolutionSize.width*0.5, designResolutionSize.height*0.5);
	battleSuccess->setVisible(false);
	battleSuccess->setContentSize(Size(400, 300));
	buttonSuccess = Button::create("confirm.png", "confirm1.png");
	battleSuccess->addChild(buttonSuccess);
	buttonSuccess->setPosition(Vec2(200,40));
	buttonSuccess->setEnabled(false);
	buttonSuccess->addClickEventListener([=](Ref* ref) {
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		GlobalInstanceClass::playMusic("03.mp3");
		auto scene = SceneMenu::create();
		Director::sharedDirector()->replaceScene(scene);
	});
	this->addChild(battleSuccess, 2);
	//失败窗口
	battleFailed = Sprite::create("battleFailed.png");
	battleFailed->setPosition(designResolutionSize.width * 0.5, designResolutionSize.height * 0.5);
	battleFailed->setVisible(false);
	battleFailed->setContentSize(Size(400, 300));
	buttonFailed = Button::create("confirm.png", "confirm1.png");
	battleFailed->addChild(buttonFailed);
	buttonFailed->setPosition(Vec2(200, 40));
	buttonFailed->setEnabled(false);
	buttonFailed->addClickEventListener([=](Ref* ref) {
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		GlobalInstanceClass::playMusic("03.mp3");
		auto scene = SceneMenu::create();
		Director::sharedDirector()->replaceScene(scene);
	});
	this->addChild(battleFailed, 2);

	
	
	return true;
}


void SceneBattle::playerAttack(float dt) {
	GlobalInstanceClass::player->attack(GlobalInstanceClass::enemy);
}

void SceneBattle::enemyAttack(float dt) {
	GlobalInstanceClass::enemy->attack(GlobalInstanceClass::player);
}

void SceneBattle::playerEndSkill(float dt) {
	GlobalInstanceClass::player->endSkill();
}

void SceneBattle::enemyEndSkill(float dt) {
	GlobalInstanceClass::enemy->endSkill();
}

void SceneBattle::playerEndSpeedSkill(float dt) {
	GlobalInstanceClass::player->endSkill();//结束技能
	this->unschedule(SEL_SCHEDULE(&SceneBattle::playerAttack));//卸载攻速提升以后的自动攻击定时器
	this->schedule(SEL_SCHEDULE(&SceneBattle::playerAttack), float(1 / GlobalInstanceClass::player->basicSpeed));//依据基础的攻速注册自动攻击定时器
}

void SceneBattle::enemyEndSpeedSkill(float dt) {
	GlobalInstanceClass::enemy->endSkill();//结束技能
	this->unschedule(SEL_SCHEDULE(&SceneBattle::enemyAttack));//卸载攻速提升以后的自动攻击定时器
	this->schedule(SEL_SCHEDULE(&SceneBattle::enemyAttack), float(1 / GlobalInstanceClass::enemy->basicSpeed));//依据基础的攻速注册自动攻击定时器
}

//每帧都执行的定时器函数
void SceneBattle::update(float dt) {
	//更新角色血条和怒气条
	playerBloodBar->setContentSize(Size((GlobalInstanceClass::player->currentHealth / GlobalInstanceClass::player->maxHealth) * BLDBW, BLDBH/2));
	playerAngerBar->setContentSize(Size((GlobalInstanceClass::player->currentAnger / GlobalInstanceClass::player->maxAnger) * BLDBW, BLDBH/2));
	enemyBloodBar->setContentSize(Size((GlobalInstanceClass::enemy->currentHealth / GlobalInstanceClass::enemy->maxHealth) * BLDBW, BLDBH/2));
	enemyAngerBar->setContentSize(Size((GlobalInstanceClass::player->currentAnger / GlobalInstanceClass::player->maxAnger) * BLDBW, BLDBH/2));


	//玩家技能触发
	if (GlobalInstanceClass::player->currentAnger >= GlobalInstanceClass::player->maxAnger) {
		GlobalInstanceClass::player->runSkill();//触发技能

		//如果触发的是提升攻速的技能
		if (GlobalInstanceClass::player->currentSpeed > GlobalInstanceClass::player->basicSpeed) {
			this->unschedule(SEL_SCHEDULE(&SceneBattle::playerAttack));//卸载旧的自动攻击定时器
			this->schedule(SEL_SCHEDULE(&SceneBattle::playerAttack), float(1 / GlobalInstanceClass::player->currentSpeed));//依据提升以后的攻速注册新的自动攻击定时器
			this->scheduleOnce(SEL_SCHEDULE(&SceneBattle::playerEndSpeedSkill),5);//5秒后恢复正常
		}
		else/*触发的不是攻速技能*/ this->scheduleOnce(SEL_SCHEDULE(&SceneBattle::playerEndSkill), 5);//5秒后结束技能
	}


	//敌人技能触发
	if (GlobalInstanceClass::enemy->currentAnger >= GlobalInstanceClass::enemy->maxAnger) {
		GlobalInstanceClass::enemy->runSkill();//触发技能

		//如果触发的是提升攻速的技能
		if (GlobalInstanceClass::enemy->currentSpeed > GlobalInstanceClass::enemy->basicSpeed) {
			this->unschedule(SEL_SCHEDULE(&SceneBattle::enemyAttack));//卸载旧的自动攻击定时器
			this->schedule(SEL_SCHEDULE(&SceneBattle::enemyAttack), float(1 / GlobalInstanceClass::enemy->currentSpeed));//依据提升以后的攻速注册新的自动攻击定时器
			this->scheduleOnce(SEL_SCHEDULE(&SceneBattle::enemyEndSpeedSkill), 5);//5秒后恢复正常
		}
		else/*触发的不是攻速技能*/ this->scheduleOnce(SEL_SCHEDULE(&SceneBattle::enemyEndSkill), 5);//5秒后结束技能
	}

	//玩家和敌人中的一方死亡
	if (GlobalInstanceClass::player->currentHealth <= 0 || GlobalInstanceClass::enemy->currentHealth <= 0) {
		//玩家获胜
		if (GlobalInstanceClass::player->currentHealth > GlobalInstanceClass::enemy->currentHealth) {
			GlobalInstanceClass::player->level += 5;
			battleSuccess->setVisible(true);
			buttonSuccess->setEnabled(true);
			this->unscheduleAllSelectors();//停止所有定时器
		}
		//敌人获胜
		else {
			battleFailed->setVisible(true);
			buttonFailed->setEnabled(true);
			this->unscheduleAllSelectors();//停止所有定时器
		}
	}
}
