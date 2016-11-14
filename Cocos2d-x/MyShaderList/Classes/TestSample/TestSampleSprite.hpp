//
//  TestSampleSprite.hpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/30.
//
//

#ifndef TestSampleSprite_hpp
#define TestSampleSprite_hpp

#include <stdio.h>
#include "QFLLayerBase.hpp"

class TestSampleSprite : public QFLLayerBase
{
public:
    TestSampleSprite();
    virtual ~TestSampleSprite();
    CREATE_FUNC(TestSampleSprite);
    
private:
    virtual void enterTest() override;
    
    void addItems();
    void showTest(const std::string &strName);
    
    /*
     工具
     */
    
    //获得文件字符串
    std::string getStringFromFile(const std::string &strName);
    
    //更换一个新的测试精灵
    cocos2d::Sprite* replaceOrCreateTestSprite();
    
    //根据file获得一个GLProgramState
    cocos2d::GLProgramState* getGLProgrameState(const std::string &vshName, const std::string &fshName);
};

#endif /* TestSampleSprite_hpp */
