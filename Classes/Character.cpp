#include "Character.h"
#include <ctime>

void Character::attack(Character* chara) {
	//造成伤害
	srand(clock());
	int r = rand();
	double p = (double(( r % 101)) / 100 + 0.5);
	double damage = (this->currentDamage - chara->currentDefence)* p;//有效伤害
	if (damage > 0) {
		chara->currentHealth -= damage;
		//被击方呻吟
		chara->groan();
		//被击方抖动
		chara->runAction(Shake::create(0.2, 50));

		//在被击方附近显示伤害
		Label* damageLabel = Label::createWithTTF(std::to_string(int(damage)), "fonts\\Marker Felt.ttf", 30);
		chara->addChild(damageLabel);
		damageLabel->setPosition(chara->getContentSize());
		//0.5秒后伤害信息消失
		chara->scheduleOnce([=](float dt) {
			chara->removeChild(damageLabel, true);
		}, 0.5, "damageInfo");
	}
	else {
		//在被击方附近显示MISS
		Label* damageLabel = Label::createWithTTF("MISS", "fonts\\Marker Felt.ttf", 30);
		chara->addChild(damageLabel);
		damageLabel->setPosition(chara->getContentSize());
		//0.5秒后伤害信息消失
		chara->scheduleOnce([=](float dt) {
			chara->removeChild(damageLabel, true);
		}, 0.5, "damageInfo");
	}
	//双方怒气增加
	this->currentAnger += 3;
	chara->currentAnger += 7;
}

void Character::equipWeapon(Weapon* weapon) {
	this->weapon = weapon;
	weapon->equip(this);
}

void Character::removeWeapon() {
	if (this->weapon == nullptr) return;
	weapon->remove();
	this->weapon = nullptr;
}

void Character::refresh() {
	//health
	this->maxHealth = this->levelZeroHealth + (this->level*this->levelUpIncreaseHealth);
	this->currentHealth = this->maxHealth;
	//damage
	this->basicDamage = this->levelZeroDamage + (this->level*this->levelUpIncreaseDamage);
	this->currentDamage = this->basicDamage;
	//defence
	this->basicDefence = this->levelZeroDefence + (this->level*this->levelUpIncreaseDefence);
	this->currentDefence = this->basicDefence;
	//speed
	this->basicSpeed = this->levelZeroSpeed + (this->level*this->levelUpIncreaseSpeed);
	this->currentSpeed = this->basicSpeed;
	//anger
	this->currentAnger = 0;
}