#ifndef _GLOBALINSTANCECLASS_H
#define _GLOBALINSTANCECLASS_H

#include "CharacterA.h"
#include "CharacterB.h"
#include "CharacterC.h"
#include "CharacterD.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

class GlobalInstanceClass {
public:
	static Character* player;

	static Character* enemy;

	static bool isGameSaved;

	static void createAllGlobalInstance();//创建游戏需要的所有自定义单例对象

	static void firstInitializeAll();//游戏初次运行时初始化所有单例对象

	static CharacterA* getCharaA();

	static CharacterB* getCharaB();

	static CharacterC* getCharaC();

	static CharacterD* getCharaD();

	static bool saveAll();

	static bool loadAll();

	static void playMusicEffect(const char* file);

	static void playMusic(const char* file);

	//音效是否打开
	static bool musicEffect;

	static bool music;
};







#endif // !_GLOBALINSTANCECLASS_H
