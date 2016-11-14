//
//  QFLLayerBase.cpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/23.
//
//

#include "QFLLayerBase.hpp"

USING_NS_CC;

QFLLayerBase::QFLLayerBase()
{
    
}

QFLLayerBase::~QFLLayerBase()
{
    
}

QFLLayerBase* QFLLayerBase::create()
{
    QFLLayerBase* pLayer = new(std::nothrow) QFLLayerBase();
    if (pLayer && pLayer->init()) {
        pLayer->autorelease();
        return pLayer;
    }
    else {
        CC_SAFE_DELETE(pLayer);
        return nullptr;
    }
}

bool QFLLayerBase::init()
{
    if (Layer::init()) {
        this->addLayerUI();
        this->enterTest();
        return true;
    }
    else {
        return false;
    }
}

void QFLLayerBase::addLayerUI()
{
    //黑色背景
    auto pBGLayer = QFL_HELPER->getBlackBGLayer();
    this->addChild(pBGLayer);
    
    //返回按钮
    QFL_HELPER->addBackMenu(this);
}

void QFLLayerBase::enterTest()
{
    log("Need to override method enterTest.");
}

