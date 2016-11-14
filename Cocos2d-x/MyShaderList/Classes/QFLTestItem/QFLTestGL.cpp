//
//  QFLTestGL.cpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/11/1.
//
//

#include "QFLTestGL.hpp"

USING_NS_CC;

QFLTestGL::QFLTestGL()
{
    
}

QFLTestGL::~QFLTestGL()
{
    
}

void QFLTestGL::enterTest()
{
    this->addTestItem();
}

void QFLTestGL::addTestItem()
{
    
}

void QFLTestGL::visit(cocos2d::Renderer *pRenderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags)
{
    //调用父类函数
    Layer::visit(pRenderer, parentTransform, parentFlags);
    //初始化命令
    m_command.init(_globalZOrder);
    m_command.func = CC_CALLBACK_0(QFLTestGL::onDraw, this);    //当命令被处理时会调用到这回调
    //添加绘制命令
    Director::getInstance()->getRenderer()->addCommand(&m_command);
}

void QFLTestGL::onDraw()
{
    //获得glProgram
    auto pProgram = getGLProgram();
    //激活glProgram
    pProgram->use();
    //设置内置uniform
    pProgram->setUniformsForBuiltins();
    
    auto sizeWin = Director::getInstance()->getWinSize();
    //指定三个顶点,【左下角，右下角，顶部中心点】
    float vertercies[] = {0.0, 0.0, sizeWin.width, 0.0, sizeWin.width / 2, sizeWin.height};
    //指定定点颜色
    float color[] = {1, 0, 0, 1,    //左下角点，255,0,0,255
                     0, 0, 1, 1,    //右下角点，0,0,255,255
                     0, 1, 0, 1};   //顶部中心，0,255,0,255
    
    //激活顶点着色器的position和color属性
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
    //指定数据源
    glVertexAttribPointer(GL::VERTEX_ATTRIB_FLAG_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertercies);
    glVertexAttribPointer(GL::VERTEX_ATTRIB_FLAG_COLOR, 4, GL_FLOAT, GL_FALSE, 0, color);
    
    //调用绘制函数
    glDrawArrays(GL_TRIANGLES, 0, 3);
    //通知2dx的renderer
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
    //检查错误
    CHECK_GL_ERROR_DEBUG();
    
//    this->setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_COLOR));
}
