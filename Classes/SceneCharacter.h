#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

using namespace cocos2d::ui;

class SceneCharacter : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	Menu *buttonBack;

	Button *buttonToWeapon;

	Button *buttonCharacterA;

	Button *buttonCharacterB;

	Button *buttonCharacterC;

	Button *buttonCharacterD;

	void buttonBackClick(cocos2d::Object *Sender);

	void buttonToWeaponClick(cocos2d::Object *Sender);


	CREATE_FUNC(SceneCharacter);
};

#endif 
