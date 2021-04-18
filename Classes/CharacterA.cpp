#include "CharacterA.h"


CharacterA* CharacterA::chara = NULL;//静态全局对象初始化


CharacterA* CharacterA::create(const std::string& filename)
{
	CharacterA *sprite = new (std::nothrow) CharacterA();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
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
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}


CharacterA* CharacterA::getChara() {
	//角色A初始化
	if (chara == NULL) {
		chara = CharacterA::create("Helloworld.png");
	}
	return chara;
}

void CharacterA::runSkill() {

}

void CharacterA::endSkill() {

}

void CharacterA::firstInitialize() {
	this->level = 0;
	this->ownership = true;
}

void CharacterA::saveData() {
	UserDefault::sharedUserDefault()->setIntegerForKey("charaALevel", this->level);
	UserDefault::sharedUserDefault()->setBoolForKey("charaAOwnership", this->ownership);
}

void CharacterA::loadData() {
	this->level = UserDefault::sharedUserDefault()->getIntegerForKey("charaALevel");
	this->ownership = UserDefault::sharedUserDefault()->getBoolForKey("charaAOwnership");
}