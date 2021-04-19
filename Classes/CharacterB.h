#ifndef _CHARACTERB_H
#define _CHARACTERB_H

#include "Character.h"


class CharacterB : public Character {
private:
	static CharacterB* chara;//单例成员
	static CharacterB* create(const std::string& filename);//工厂函数私有化
public:
	static CharacterB* getChara();//获取单例

	virtual void runSkill()override;

	virtual void endSkill()override;

	virtual void firstInitialize();

	virtual void saveData()override;

	virtual void loadData()override;
};

#endif // !_CHARACTERB_H
