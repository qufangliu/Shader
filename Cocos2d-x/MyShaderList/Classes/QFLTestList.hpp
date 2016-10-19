//
//  QFLTestList.hpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/20.
//
//

#ifndef QFLTestList_hpp
#define QFLTestList_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class QFLTestList : public cocos2d::Layer
{
CC_CONSTRUCTOR_ACCESS:
    QFLTestList();
    virtual ~QFLTestList();
    virtual bool init();
    CREATE_FUNC(QFLTestList);
    
    static cocos2d::Scene* createScene();
    
private:
    void addListUI();
    void addTestItem();
    void addItem(const std::string &strItem, const std::function<void()> &funcTest);
    
private:
    cocos2d::ui::ListView *m_pTestList;
    
    int m_nItemCounter;
};

#endif /* QFLTestList_hpp */
