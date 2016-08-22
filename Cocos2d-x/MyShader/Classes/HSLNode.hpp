//
//  HSLNode.hpp
//  MyShader
//
//  Created by QuFangliu on 16/7/8.
//
//

#ifndef HSLNode_hpp
#define HSLNode_hpp

#include <stdio.h>

class HSLNode : public cocos2d::Node
{
public:
    virtual bool init();
    CREATE_FUNC(HSLNode);
    
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

#endif /* HSLNode_hpp */
