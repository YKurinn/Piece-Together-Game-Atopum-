#include "GlobalInstanceClass.h"



void GlobalInstanceClass::createAll() {
	CharacterA::getChara();
}


CharacterA* GlobalInstanceClass::getCharaA() {
	return CharacterA::getChara();
}