#ifndef _WEAPON_H
#define _WEAPON_H

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;

class Character;

class Weapon :public Sprite{
	public:
		std::string name;
        double increasePercent;
        std::string increaseType;
        Character* owner;

		static Weapon* create(const std::string& filename,double increasePercent,std::string increaseType);

        void equip(Character* chara);

        void remove();

};







#endif _WEAPON_H