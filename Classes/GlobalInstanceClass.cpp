#include "GlobalInstanceClass.h"

Character* GlobalInstanceClass::enemy = nullptr;
Character* GlobalInstanceClass::player = nullptr;
bool GlobalInstanceClass::isGameSaved = nullptr;

void GlobalInstanceClass::createAllGlobalInstance() {
	CharacterA::getChara();
	CharacterB::getChara();
	CharacterC::getChara();
	CharacterD::getChara();
}


CharacterA* GlobalInstanceClass::getCharaA() {
	return CharacterA::getChara();
}


CharacterB* GlobalInstanceClass::getCharaB() {
	return CharacterB::getChara();
}


CharacterC* GlobalInstanceClass::getCharaC() {
	return CharacterC::getChara();
}


CharacterD* GlobalInstanceClass::getCharaD() {
	return CharacterD::getChara();
}


bool GlobalInstanceClass::saveAll() {
	CharacterA::getChara()->saveData();
	CharacterB::getChara()->saveData();
	CharacterC::getChara()->saveData();
	CharacterD::getChara()->saveData();
	
	return true;
}


bool GlobalInstanceClass::loadAll() {
	CharacterA::getChara()->loadData();
	CharacterB::getChara()->loadData();
	CharacterC::getChara()->loadData();
	CharacterD::getChara()->loadData();
	return true;
}

void GlobalInstanceClass::firstInitializeAll() {
	CharacterA::getChara()->firstInitialize();
	CharacterB::getChara()->firstInitialize();
	CharacterC::getChara()->firstInitialize();
	CharacterD::getChara()->firstInitialize();
}