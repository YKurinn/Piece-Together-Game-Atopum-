#ifndef _CHARACTERC_H
#define _CHARACTERC_H

#include "Character.h"


class CharacterC : public Character {
private:
	static CharacterC* chara;//单例成员
	static CharacterC* create(const std::string& filename);//工厂函数私有化
public:
	static CharacterC* getChara();//获取单例

	virtual void runSkill()override;

	virtual void endSkill()override;

	virtual void firstInitialize();

	virtual void saveData()override;

	virtual void loadData()override;
};

#endif // !_CHARACTERC_H
