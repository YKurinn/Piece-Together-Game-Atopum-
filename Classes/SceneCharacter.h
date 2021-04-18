#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"
USING_NS_CC;


class SceneCharacter : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	Menu *buttonBack;

	Menu *buttonToWeapon;

	void buttonBackClick(cocos2d::Object *Sender);

	void buttonToWeaponClick(cocos2d::Object *Sender);


	CREATE_FUNC(SceneCharacter);
};

#endif 
