#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__


#include "cocos2d.h"

USING_NS_CC;

class SceneMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	Menu *buttonStart;
	Menu *buttonSetting;
	Menu *buttonSetu;
	Menu *buttonSave;
	Menu *buttonExit;

	void buttonStartClick(cocos2d::Object *Sender);
	void buttonSettingClick(cocos2d::Object *Sender);
	void buttonSetuClick(cocos2d::Object *Sender);
	void buttonSaveClick(cocos2d::Object *Sender);
	void buttonExitClick(cocos2d::Object *Sender);

    CREATE_FUNC(SceneMenu);
};


#endif // __HELLOWORLD_SCENE_H__
