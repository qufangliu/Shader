//
//  HSLSprite.hpp
//  MyShader
//
//  Created by QuFangliu on 16/6/13.
//
//

#ifndef HSLSprite_hpp
#define HSLSprite_hpp

#include <stdio.h>
#include "cocos2d.h"

class HSLSprite : public cocos2d::Sprite
{
public:
    virtual bool init();
    CREATE_FUNC(HSLSprite);
    
    void setHSLMode();
    void setHSL(float h , float s, float l);
    void updateHSL();
    
    float m_dH;
    float m_dS;
    float m_dL;
    
    GLuint m_dHlocation;
    GLuint m_dSlocation;
    GLuint m_dLlocation;
    
    //这一段是为了做动态修改，额外添加的取值和设置方法
    void setH(float h);
    float getH(){return m_dH;}
    void setS(float s);
    float getS(){return m_dS;}
    void setL(float l);
    float getL(){return m_dL;}
};

#endif /* HSLSprite_hpp */
