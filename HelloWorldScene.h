#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void myUpdate(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    Sprite *_player,*_target;
    
private:
    
    //Point count(Point s,Point t);
    //bool isbong(Point p1,Point p2,float r1,float r2);
};

#endif // __HELLOWORLD_SCENE_H__
