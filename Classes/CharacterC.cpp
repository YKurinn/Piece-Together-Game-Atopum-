#include "CharacterC.h"


CharacterC* CharacterC::chara = nullptr;//静态全局对象初始化


CharacterC* CharacterC::create(const std::string& filename)
{
	CharacterC* sprite = new (std::nothrow) CharacterC();
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


CharacterC* CharacterC::getChara() {
	//角色A初始化
	if (chara == nullptr) {
		chara = CharacterC::create("charaC.png");
	}
	return chara;
}

void CharacterC::runSkill() {

}

void CharacterC::endSkill() {

}

void CharacterC::firstInitialize() {
	this->level = 0;
	this->ownership = false;
}

void CharacterC::saveData() {
	UserDefault::sharedUserDefault()->setIntegerForKey("charaCLevel", this->level);
	UserDefault::sharedUserDefault()->setBoolForKey("charaCOwnership", this->ownership);
}

void CharacterC::loadData() {
	this->level = UserDefault::sharedUserDefault()->getIntegerForKey("charaCLevel");
	this->ownership = UserDefault::sharedUserDefault()->getBoolForKey("charaCOwnership");
}