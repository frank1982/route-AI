#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    //this->schedule(schedule_selector(HelloWorld::myUpdate, 0.5));
    this->schedule(schedule_selector(HelloWorld::myUpdate), 0.5);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    _target=Sprite::create("hero1.jpg");
    _target->setScale(0.1);
    _target->setPosition(visibleSize.width-100,100);
    addChild(_target);

    _player=Sprite::create("warrior.jpg");
    _player->setScale(0.1);
    _player->setPosition(visibleSize.width/2,visibleSize.height-100);
    addChild(_player);
    
    
    auto move=MoveTo::create(10, Point(100,100));
    _target->runAction(move);
    
    return true;
}

void HelloWorld::myUpdate(float dt){
    
    log("update");
    auto self=_player->getPosition();
    auto target=_target->getPosition();
    
    float distance=sqrt(powf(target.y-self.y, 2)+powf(target.x-self.x, 2));
    float distanceX=target.x-self.x;
    float distanceY=target.y-self.y;
    
    Point mid;
    
    float vec=60;
    
    log("distance is: %f",distance);
    
    
    mid.x=(vec/distance)*distanceX+self.x;
    
    mid.y=(vec/distance)*distanceY+self.y;
    
     log("mid.x is %f,mid.y is%f",mid.x,mid.y);
    
    auto move=MoveTo::create(dt, mid);
    
    auto RecT=CCRectMake(_target->getPosition().x-_target->getContentSize().width*0.1/2, _target->getPosition().y-_target->getContentSize().height*0.1/2, _target->getContentSize().width*0.1, _target->getContentSize().height*0.1);
    
    auto RecS=CCRectMake(_player->getPosition().x-_player->getContentSize().width*0.1/2, _player->getPosition().y-_player->getContentSize().height*0.1/2, _player->getContentSize().width*0.1, _player->getContentSize().height*0.1);
    
    if(RecS.intersectsRect(RecT)){
        _player->stopAllActions();
    }else{
        
        auto move=MoveTo::create(dt, mid);
        _player->runAction(move);
    }
    
    
};










