//
//  TestColorScene.hpp
//  MyShader
//
//  Created by QuFangliu on 16/6/13.
//
//

#ifndef TestColorScene_hpp
#define TestColorScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class TestColorScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    void loadResource();
    void addUI();
    CREATE_FUNC(TestColorScene);
    
};

#endif /* TestColorScene_hpp */
