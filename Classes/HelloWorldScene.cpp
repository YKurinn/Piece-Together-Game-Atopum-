#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    
    if ( !Scene::init() )
    {
        return false;
    }


    
    return true;
}
