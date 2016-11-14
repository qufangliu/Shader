//
//  QFLTestSprite.hpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/30.
//
//

#ifndef QFLTestSprite_hpp
#define QFLTestSprite_hpp

#include <stdio.h>
#include "QFLLayerBase.hpp"

class QFLTestSprite : public QFLLayerBase
{
public:
    QFLTestSprite();
    virtual ~QFLTestSprite();
    CREATE_FUNC(QFLTestSprite);
    
private:
    virtual void enterTest();
    
    void addMenu();
    void showTestItem(const std::string &strTestName);
    
    cocos2d::Sprite* replaceOrCreateSprite();
    cocos2d::GLProgramState* getGLProgramState(const std::string &strVshName, const std::string &strFshName);
};

#endif /* QFLTestSprite_hpp */
