//
//  QFLLayerBase.hpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/23.
//
//

#ifndef QFLLayerBase_hpp
#define QFLLayerBase_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "QFLTools/QFLHelper.hpp"

class QFLLayerBase : public cocos2d::Layer
{
CC_CONSTRUCTOR_ACCESS:
    QFLLayerBase();
    virtual ~QFLLayerBase();
    virtual bool init();
    static QFLLayerBase* create();
    
    virtual void enterTest();
    
private:
    void addLayerUI();  //添加测试需要的默认UI
};

#endif /* QFLLayerBase_hpp */
