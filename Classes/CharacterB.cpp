#include "CharacterB.h"
#include "GlobalInstanceClass.h"


CharacterB* CharacterB::chara = nullptr;//静态全局对象初始化


CharacterB* CharacterB::create(const std::string& filename)
{
	CharacterB* sprite = new (std::nothrow) CharacterB();
	if (sprite && sprite->initWithFile(filename))
	{
		//sprite->autorelease();
		//name
		sprite->name = "Sikadi";
		//health
		sprite->levelZeroHealth = 1000;
		sprite->levelUpIncreaseHealth = 100;
		//damage
		sprite->levelZeroDamage = 100;
		sprite->levelUpIncreaseDamage = 15;
		//defence
		sprite->levelZeroDefence = 0;
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


CharacterB* CharacterB::getChara() {
	//角色B初始化
	if (chara == nullptr) {
		chara = CharacterB::create("charaB.png");
	}
	return chara;
}

void CharacterB::runSkill() {
	this->currentAnger = 0;
	this->currentHealth += 0.15*this->maxHealth;
	if (this->currentHealth > this->maxHealth)this->currentHealth = this->maxHealth;
	GlobalInstanceClass::playMusicEffect("audioCharaBSkill.wav");

}

void CharacterB::endSkill() {

}

void CharacterB::firstInitialize() {
	this->level = 0;
	this->ownership = false;
}

void CharacterB::saveData() {
	UserDefault::sharedUserDefault()->setIntegerForKey("charaBLevel", this->level);
	UserDefault::sharedUserDefault()->setBoolForKey("charaBOwnership", this->ownership);
}

void CharacterB::loadData() {
	this->level = UserDefault::sharedUserDefault()->getIntegerForKey("charaBLevel");
	this->ownership = UserDefault::sharedUserDefault()->getBoolForKey("charaBOwnership");
}

void CharacterB::groan() {
	GlobalInstanceClass::playMusicEffect("audioCharaBGroan.wav");
}