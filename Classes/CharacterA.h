#ifndef _CHARACTERA_H
#define _CHARACTERA_H

#include "Character.h"


class CharacterA : public Character {
private:
	static CharacterA* chara;//单例成员
	
public:
	static CharacterA* create(const std::string& filename);//工厂函数
	
	static CharacterA* getChara();//获取单例

	virtual void runSkill()override;

	virtual void endSkill()override;

	virtual void firstInitialize();

	virtual void saveData()override;

	virtual void loadData()override;

	virtual void groan();

};

#endif // !_CHARACTERA_H
