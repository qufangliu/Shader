//
//  QFLTestList.cpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/20.
//
//

#include "QFLTestList.hpp"

//工具类
#include "QFLTools/QFLHelper.hpp"

//测试类
#include "QFLTestItem/Test_1/QFLTestTIle.hpp"

USING_NS_CC;

QFLTestList::QFLTestList()
{
    
}

QFLTestList::~QFLTestList()
{
    
}

Scene* QFLTestList::createScene()
{
    auto pScene = Scene::create();
    auto pLayer = QFLTestList::create();
    pScene->addChild(pLayer);
    return pScene;
}

bool QFLTestList::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addListUI();
        return true;
    }
}

void QFLTestList::addListUI()
{
    //生成列表
    m_pTestList = ui::ListView::create();
    m_pTestList->setContentSize(SCREEN_VISIBLE_SIZE);
    m_pTestList->setPosition(SCREEN_VISIBLE_ORIGIN);
    m_pTestList->setGravity(cocos2d::ui::ListView::Gravity::CENTER_VERTICAL);
    m_pTestList->setBounceEnabled(true);
    m_pTestList->setScrollBarEnabled(false);
    this->addChild(m_pTestList);
    
    //初始化菜单计数
    m_nItemCounter = 0;
    
    //添加测试项目
    this->addTestItem();
}

void QFLTestList::addTestItem()
{
    //测试Item
    this->addItem("TestTile", [=](){
        this->addChild(QFLTestTile::create());
    });
}

void QFLTestList::addItem(const std::string &strItem, const std::function<void ()> &funcTest)
{
    //计数
    m_nItemCounter++;
    
    //生成item
    auto pModel = cocos2d::ui::Widget::create();
    pModel->setContentSize(Size(SCREEN_WIDTH, 50.0f));
    
    //添加Label
    auto pLabel = Label::createWithSystemFont(StringUtils::format("%d:%s", m_nItemCounter, strItem.c_str()),
                                              QFLConfig::strSystemFontName,
                                              QFLConfig::nSystemFontSize);
    pLabel->setPosition(pModel->getContentSize() * 0.5);
    pModel->addChild(pLabel);
    
    //添加事件
    pModel->setTouchEnabled(true);//不设置的话不会响应事件
    pModel->addClickEventListener([=](Ref* pRef){
        funcTest();
    });
    
    //添加Item
    m_pTestList->pushBackCustomItem(pModel);
}

