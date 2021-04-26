#include "Weapon.h"
#include "Character.h"


Weapon* Weapon::create(const std::string& filename,std::string name, double increasePercent, std::string increaseType)
{
	Weapon *weapon = new (std::nothrow) Weapon();
	if (weapon && weapon->initWithFile(filename))
	{
		//weapon->autorelease();
		weapon->name = name;
		weapon->increasePercent = increasePercent;
		weapon->increaseType = increaseType;
		return weapon;
	}
	CC_SAFE_DELETE(weapon);
	return nullptr;
}

void Weapon::equip(Character* chara) {
	this->owner = chara;

	if (this->increaseType == "health") {
		chara->maxHealth *= (1 + this->increasePercent);
		chara->currentHealth = chara->maxHealth;
	}
	else if (this->increaseType == "defence") {
		chara->basicDefence *= (1 + this->increasePercent);
		chara->currentDefence = chara->basicDefence;
	}
	else if (this->increaseType == "damage") {
		chara->basicDamage *= (1 + this->increasePercent);
		chara->currentDamage = chara->basicDamage;
	}
	else if (this->increaseType == "speed") {
		chara->basicSpeed *= (1 + this->increasePercent);
		chara->currentSpeed = chara->basicSpeed;
	}
}

void Weapon::remove() {
	if (this->owner == nullptr)return;

	if (this->increaseType == "health") {
		owner->maxHealth /= (1 + this->increasePercent);
		owner->currentHealth = owner->maxHealth;
	}
	else if (this->increaseType == "defence") {
		owner->basicDefence /= (1 + this->increasePercent);
		owner->currentDefence = owner->basicDefence;
	}
	else if (this->increaseType == "damage") {
		owner->basicDamage /= (1 + this->increasePercent);
		owner->currentDamage = owner->basicDamage;
	}
	else if (this->increaseType == "speed") {
		owner->basicSpeed /= (1 + this->increasePercent);
		owner->currentSpeed = owner->basicSpeed;
	}
	this->owner = nullptr;
	
	delete this;
}