#include "CharacterD.h"


CharacterD* CharacterD::chara = nullptr;//静态全局对象初始化


CharacterD* CharacterD::create(const std::string& filename)
{
	CharacterD* sprite = new (std::nothrow) CharacterD();
	if (sprite && sprite->initWithFile(filename))
	{
		//sprite->autorelease();
		//name
		sprite->name = "坂上智代";
		//health
		sprite->levelZeroHealth = 1000;
		sprite->levelUpIncreaseHealth = 100;
		//damage
		sprite->levelZeroDamage = 100;
		sprite->levelUpIncreaseDamage = 15;
		//defence
		sprite->levelZeroDefence = 50;
		sprite->levelUpIncreaseDefence = 5;
		//speed
		sprite->levelZeroSpeed = 0.5;
		sprite->levelUpIncreaseSpeed = 0.01;
		sprite->firstInitialize();

		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}


CharacterD* CharacterD::getChara() {
	//角色A初始化
	if (chara == nullptr) {
		chara = CharacterD::create("charaD.png");
	}
	return chara;
}

void CharacterD::runSkill() {

}

void CharacterD::endSkill() {

}

void CharacterD::firstInitialize() {
	this->level = 0;
	this->ownership = false;
}

void CharacterD::saveData() {
	UserDefault::sharedUserDefault()->setIntegerForKey("charaDLevel", this->level);
	UserDefault::sharedUserDefault()->setBoolForKey("charaDOwnership", this->ownership);
}

void CharacterD::loadData() {
	this->level = UserDefault::sharedUserDefault()->getIntegerForKey("charaDLevel");
	this->ownership = UserDefault::sharedUserDefault()->getBoolForKey("charaDOwnership");
}