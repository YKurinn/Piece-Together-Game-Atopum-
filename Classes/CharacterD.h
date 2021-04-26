#ifndef _CHARACTERD_H
#define _CHARACTERD_H

#include "Character.h"

class CharacterD : public Character {
private:
	static CharacterD* chara;//单例成员
	
public:
	static CharacterD* create(const std::string& filename);//工厂函数

	static CharacterD* getChara();//获取单例

	virtual void runSkill()override;

	virtual void endSkill()override;

	virtual void firstInitialize();

	virtual void saveData()override;

	virtual void loadData()override;

	virtual void groan();

};

#endif // !_CHARACTERD_H
