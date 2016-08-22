#include "HelloWorldScene.h"
#include "CCSpriteWithHue.h"
#include "ui/UISlider.h"

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
    //修改色相
    auto alien = SpriteWithHue::create("alien.png");
    alien->setPosition(Vec2(visibleSize.width * 0.5, visibleSize.height * 0.5));
    this->addChild(alien,1);
    
    auto label = Label::createWithSystemFont("Percent:0->Hue:0.0", "", 24);
    label->setPosition(Vec2(visibleSize.width * 0.5, 24));
    this->addChild(label);
    
    cocos2d::ui::Slider* pSlider = cocos2d::ui::Slider::create("Slider_Bar.png", "Slider_Ball.png");
    pSlider->setPosition(Vec2(visibleSize.width * 0.5, 50));
    pSlider->addEventListener([=](Ref* ref,ui::Slider::EventType type){
        if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
            int p = pSlider->getPercent();
            float hue = 2 * M_PI * pSlider->getPercent() / 100;
            alien->setHue(hue);
            label->setString(StringUtils::format("Percent:%d->Hue:%f", p, hue));
        }
        else {
            
        }
    });
    
    this->addChild(pSlider);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
