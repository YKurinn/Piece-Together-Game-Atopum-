#include "Weapon.h"
#include "Character.h"


Weapon* Weapon::create(const std::string& filename, double increasePercent, std::string increaseType)
{
	Weapon *weapon = new (std::nothrow) Weapon();
	if (weapon && weapon->initWithFile(filename))
	{
		weapon->autorelease();
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
	}
	else if (this->increaseType == "defence") {
		chara->basicDefence *= (1 + this->increasePercent);
	}
	else if (this->increaseType == "damage") {
		chara->basicDamage *= (1 + this->increasePercent);
	}
	else if (this->increaseType == "speed") {
		chara->basicSpeed *= (1 + this->increasePercent);
	}
}

void Weapon::remove() {
	if (this->owner == nullptr)return;

	if (this->increaseType == "health") {
		owner->maxHealth /= (1 + this->increasePercent);
	}
	else if (this->increaseType == "defence") {
		owner->basicDefence /= (1 + this->increasePercent);
	}
	else if (this->increaseType == "damage") {
		owner->basicDamage /= (1 + this->increasePercent);
	}
	else if (this->increaseType == "speed") {
		owner->basicSpeed /= (1 + this->increasePercent);
	}
	this->owner == nullptr;
	
	delete this;
}