#ifndef _GLOBALINSTANCECLASS_H
#define _GLOBALINSTANCECLASS_H

#include "CharacterA.h"


class GlobalInstanceClass {
public:
	Character* player;
	Character* enemy;

	void createAll();//创建游戏需要的所有自定义单例对象

	static CharacterA* getCharaA();
};







#endif // !_GLOBALINSTANCECLASS_H
