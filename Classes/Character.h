#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "cocos2d.h"
#include "Weapon.h"


USING_NS_CC;


class Character : public Sprite {
	public:
		std::string name;
		int level;
		bool ownership;
		//health
		double levelZeroHealth;
		double maxHealth;
		double currentHealth;
		double levelUpIncreaseHealth;
		//damage
		double levelZeroDamage;
		double basicDamage;
		double currentDamage;
		double levelUpIncreaseDamage;
		//defence
		double levelZeroDefence;
		double basicDefence;
		double currentDefence;
		double levelUpIncreaseDefence;
		//speed
		double levelZeroSpeed;
		double basicSpeed;
		double currentSpeed;
		double levelUpIncreaseSpeed;
		//anger
		double maxAnger = 50;
		double currentAnger = 0;
		Weapon* weapon;

		void attack(Character* chara);

		//子类必须实现的抽象函数
		virtual void runSkill() = 0;

		virtual void endSkill() = 0;
		
		virtual void saveData() = 0;//存储存档时调用

		virtual void loadData() = 0;//读取存档时调用

		virtual void firstInitialize();//只会在游戏第一次启动时调用

		virtual void refresh();//依据等级更新角色状态

		void equipWeapon(Weapon* weapon);

		void removeWeapon();
};


#endif // !_CHARACTER_H
