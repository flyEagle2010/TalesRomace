#include "AppDelegate.h"
#include "LoginScene.h"
#include "Update.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
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

bool AppDelegate::applicationDidFinishLaunching() {
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
    
    Size size=glview->getFrameSize();
    Size designSize(1136,640);
//    float scaleX=size.width/designSize.width;
    float scaleY=size.height/designSize.height;
//    glview->setDesignResolutionSize(size.width/scaleY,designSize.height,ResolutionPolicy::SHOW_ALL);
    

    glview->setDesignResolutionSize(1136, 640, ResolutionPolicy::FIXED_HEIGHT);
    
//    glview->setDesignResolutionSize(1136.0, 640.0, ResolutionPolicy::FIXED_WIDTH);
    std::vector<std::string>searchPath=FileUtils::getInstance()->getSearchPaths();
    searchPath.push_back("/");
    searchPath.push_back("bg");
    searchPath.push_back("bone");
    searchPath.push_back("bone/juqi_1");
    searchPath.push_back("bone/juqi_2");
    searchPath.push_back("bone/juqi_3");
    searchPath.push_back("common");
    searchPath.push_back("data");

    searchPath.push_back("Default");
    searchPath.push_back("effect");
    searchPath.push_back("fight");
    searchPath.push_back("fonts");

    searchPath.push_back("icon");
    searchPath.push_back("icon/portrait");
    searchPath.push_back("luoLi");
    searchPath.push_back("particle");
    
    
    searchPath.push_back("tmx");
    
    
    searchPath.push_back("res");
    searchPath.push_back("res/Default");
    
    
    
    FileUtils::getInstance()->setSearchPaths(searchPath);
//    director->setContentScaleFactor(640.0/320.0);

    std::string pathToSave = FileUtils::getInstance()->getWritablePath();
    pathToSave += "tmpdir";
    std::vector<std::string> searchPaths = FileUtils::getInstance()->getSearchPaths();
    std::vector<std::string>::iterator iter = searchPaths.begin();
    searchPaths.insert(iter, pathToSave);
    FileUtils::getInstance()->setSearchPaths(searchPaths);


    // create a scene. it's an autorelease object
//    auto scene = TestScene2::createScene();

    auto scene = LoginScene::createScene();
//   auto scene = Update::createScene();

//    auto scene=TestShadeScene::createScene();
    
    // run
//    director->runWithScene(scene);
//
//    Manager::getInstance()->scene=scene;
    Manager::getInstance()->initCommonRes();
    Manager::getInstance()->switchScence(scene);
   

    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyReleased =[&](EventKeyboard::KeyCode keyCode, Event* event)
    {
        if(keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE)
        {
            Director::getInstance()->end();
            #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
                exit(0);
            #endif
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, -1);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
