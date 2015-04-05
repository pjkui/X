#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "cocostudio/CCArmature.h"

using namespace cocostudio;

class testDelegate
{
public:
    virtual void testFunc() = 0;
};

class HelloWorld : public cocos2d::Layer, public testDelegate
{
private:
    Armature* armature;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void playAnimationTest(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void test1(float duration);
    void test2();
    void testFunc();
};

#endif // __HELLOWORLD_SCENE_H__
