#include "Character.h"


void Character::attack(Character* chara) {
	chara->currentHealth -= (this->currentDamage - chara->currentDefence);
	this->currentAnger += 2;
	chara->currentAnger += 5;
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