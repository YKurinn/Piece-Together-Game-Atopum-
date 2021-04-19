#ifndef _CHARACTERD_H
#define _CHARACTERD_H

#include "Character.h"


class CharacterD : public Character {
private:
	static CharacterD* chara;//单例成员
	static CharacterD* create(const std::string& filename);//工厂函数私有化
public:
	static CharacterD* getChara();//获取单例

	virtual void runSkill()override;

	virtual void endSkill()override;

	virtual void firstInitialize();

	virtual void saveData()override;

	virtual void loadData()override;
};

#endif // !_CHARACTERD_H
