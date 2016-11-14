//
//  QFLTestGL.hpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/11/1.
//
//

#ifndef QFLTestGL_hpp
#define QFLTestGL_hpp

#include <stdio.h>
#include "QFLLayerBase.hpp"

class QFLTestGL : public QFLLayerBase
{
CC_CONSTRUCTOR_ACCESS:
    QFLTestGL();
    virtual ~QFLTestGL();
    CREATE_FUNC(QFLTestGL);
    
    virtual void visit(cocos2d::Renderer *pRenderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;
    void onDraw();
    
private:
    virtual void enterTest();
    
    void addTestItem();
    
private:
    cocos2d::CustomCommand m_command;    //渲染命令
};

#endif /* QFLTestGL_hpp */
