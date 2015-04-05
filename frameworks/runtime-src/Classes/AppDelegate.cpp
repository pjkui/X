#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"
#include "HelloWorldScene.h"
#include "XBattleScene.h"

#include "SocketManager.h"

using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
//    auto engine = LuaEngine::getInstance();
//    ScriptEngineManager::getInstance()->setScriptEngine(engine);
//    lua_State* L = engine->getLuaStack()->getLuaState();
//    lua_module_register(L);
//
//    // If you want to use Quick-Cocos2d-X, please uncomment below code
//    // register_all_quick_manual(L);
//
//    if (engine->executeScriptFile("src/main.lua")) {
//        return false;
//    }
    
    
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }
    
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    
    //test socket connect
   // SocketManager::getInstance()->connectToServerTest();
    
    // create a scene. it's an autorelease object
  //  auto scene = HelloWorld::createScene();
    auto battleScene = XBattleScene::createScene();
    
    // run
    //director->runWithScene(scene);
    director->runWithScene(battleScene);

    
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
