//
//  TestColorScene.cpp
//  MyShader
//
//  Created by QuFangliu on 16/6/13.
//
//

#include "TestColorScene.hpp"
#include "HSLSprite.hpp"
#include "HSLNode.hpp"
#include "HSLArmature.hpp"
#include "ShaderArmature.hpp"   //不可用，蛋疼

#include "ui/UISlider.h"

USING_NS_CC;

cocos2d::Scene* TestColorScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TestColorScene::create();
    scene->addChild(layer);
    return scene;
}

bool TestColorScene::init(){
    if (!Layer::init()) {
        return false;
    }
    else {
        this->loadResource();
        this->addUI();
        return true;
    }
}

void TestColorScene::loadResource(){
//    cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo("Animation/Role/role0_daguai.ExportJson");
}

void TestColorScene::addUI(){
    //窗口位置
    cocos2d::Size screenSize = Director::getInstance()->getWinSize();
    
//    //测试用节点
//    HSLSprite* sp = HSLSprite::create();
//    sp->initWithFile("alien.png");
//    sp->setPosition(Vec2(sp->getContentSize().width * 0.5, screenSize.height * 0.5));
//    sp->setHSLMode();
//    this->addChild(sp);
    
    //在HSLNode上的子节点不受影响，尼玛啊
//    HSLNode* sp = HSLNode::create();
//    auto subSp = Sprite::create("alien.png");
//    subSp->setPosition(Vec2::ZERO);
//    sp->addChild(subSp);
//    sp->setPosition(Vec2(subSp->getContentSize().width * 0.5, screenSize.height * 0.5));
//    sp->setHSLMode();
//    this->addChild(sp);
    
    //对动画节点没用
//    HSLArmature* sp = (HSLArmature*)HSLArmature::create("role0_daguai");
//    sp->getAnimation()->play("changtai");
//    sp->setPosition(Vec2(100, screenSize.height * 0.5));
//    sp->setHSLMode();
//    this->addChild(sp);
    
    
//    //测试按钮
//    //H
//    auto labelH = Label::createWithSystemFont("Percent:0->Hue:0.0", "", 24);
//    labelH->setPosition(Vec2(screenSize.width - 220, screenSize.height * 0.8));
//    this->addChild(labelH);
//    
//    cocos2d::ui::Slider* pSliderH = cocos2d::ui::Slider::create("Slider_Bar.png", "Slider_Ball.png");
//    pSliderH->setPosition(Vec2(labelH->getPositionX(), labelH->getPositionY() + 30));
//    pSliderH->addEventListener([=](Ref* ref,ui::Slider::EventType event){
//        if (event == ui::Slider::EventType::ON_SLIDEBALL_DOWN || event == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
//            int p = pSliderH->getPercent();
//            float hue = 360.0 / 100 * p;
//            sp->setH(hue);
//            labelH->setString(StringUtils::format("Percent:%d->Hue:%f", p, hue));
//        }
//        else {
//            
//        }
//    });
//    this->addChild(pSliderH);
//    
//    //S
//    auto labelS = Label::createWithSystemFont("Percent:50->Saturation:0.0", "", 24);
//    labelS->setPosition(Vec2(screenSize.width - 220, screenSize.height * 0.5));
//    this->addChild(labelS);
//    
//    cocos2d::ui::Slider* pSliderS = cocos2d::ui::Slider::create("Slider_Bar.png", "Slider_Ball.png");
//    pSliderS->setPercent(50);
//    pSliderS->setPosition(Vec2(labelS->getPositionX(), labelS->getPositionY() + 30));
//    pSliderS->addEventListener([=](Ref* ref,ui::Slider::EventType event){
//        if (event == ui::Slider::EventType::ON_SLIDEBALL_DOWN || event == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
//            int p = pSliderS->getPercent();
//            float saturation = (p - 50.0) / 50.0;
//            sp->setS(saturation);
//            labelS->setString(StringUtils::format("Percent:%d->Saturation:%f", p, saturation));
//        }
//        else {
//            
//        }
//    });
//    this->addChild(pSliderS);
//    
//    
//    //L
//    auto labelL = Label::createWithSystemFont("Percent:50->Lightness:0.0", "", 24);
//    labelL->setPosition(Vec2(screenSize.width - 220, screenSize.height * 0.2));
//    this->addChild(labelL);
//    
//    cocos2d::ui::Slider* pSliderL = cocos2d::ui::Slider::create("Slider_Bar.png", "Slider_Ball.png");
//    pSliderL->setPercent(50);
//    pSliderL->setPosition(Vec2(labelL->getPositionX(), labelL->getPositionY() + 30));
//    pSliderL->addEventListener([=](Ref* ref,ui::Slider::EventType event){
//        if (event == ui::Slider::EventType::ON_SLIDEBALL_DOWN || event == ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
//            int p = pSliderL->getPercent();
//            float lightness = (p - 50.0) / 50.0;
//            sp->setL(lightness);
//            labelL->setString(StringUtils::format("Percent:%d->Lightness:%f", p, lightness));
//        }
//        else {
//            
//        }
//    });
//    this->addChild(pSliderL);
    
}











