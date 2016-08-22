//
//  HSLArmature.cpp
//  MyShader
//
//  Created by QuFangliu on 16/7/8.
//
//

#include "HSLArmature.hpp"

USING_NS_CC;

bool HSLArmature::init(){
    if (!Armature::init()) {
        return false;
    }
    else {
        m_dH = 0.0f;
        m_dS = 0.0f;
        m_dH = 0.0f;
        
        return true;
    }
}

void HSLArmature::setHSLMode() {
    BlendFunc blendFunc={GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA};
    this->setBlendFunc(blendFunc);
    
    GLchar * fragSource = (GLchar*) __String::createWithContentsOfFile(FileUtils::getInstance()->fullPathForFilename("ShaderFile/ColorHSL.fsh").c_str())->getCString();
    
    GLProgram* pProgram = new GLProgram();
    pProgram->initWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource);
    this->setGLProgram(pProgram);
    pProgram->release();    //这里release一次是为了减少一个引用？函数结束时，局部变量引用不就已经删掉了么？？
    
    CHECK_GL_ERROR_DEBUG();
    
    this->getGLProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    this->getGLProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    this->getGLProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
    CHECK_GL_ERROR_DEBUG();
    
    this->getGLProgram()->link();
    CHECK_GL_ERROR_DEBUG();
    
    this->getGLProgram()->updateUniforms();
    CHECK_GL_ERROR_DEBUG();
    
    m_dHlocation = glGetUniformLocation(getGLProgram()->getProgram(), "u_dH");
    m_dSlocation = glGetUniformLocation(getGLProgram()->getProgram(), "u_dS");
    m_dLlocation = glGetUniformLocation(getGLProgram()->getProgram(), "u_dL");
    
    updateHSL();
}
void HSLArmature::setHSL(float h , float s, float l) {
    m_dH = h;
    m_dS = s;
    m_dL = l;
    updateHSL();
}
void HSLArmature::updateHSL() {
    this->getGLProgram()->use();//修改uniform前，应该先调用GLProgram的use()函数  （非动态修改的时候没发现这个问题）
    //http://discuss.cocos2d-x.org/t/shader-uniform-not-updating-with-drawnode/26728
    
    glUniform1f(m_dHlocation,m_dH);
    glUniform1f(m_dSlocation,m_dS);
    glUniform1f(m_dLlocation,m_dL);
}

void HSLArmature::setH(float h){
    m_dH = h;
    updateHSL();
}
void HSLArmature::setS(float s){
    m_dS = s;
    updateHSL();
}
void HSLArmature::setL(float l){
    m_dL = l;
    updateHSL();
}
