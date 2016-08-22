//
//  ShaderArmature.cpp
//  MyShader
//
//  Created by QuFangliu on 16/7/9.
//
//

#include "ShaderArmature.hpp"

ShaderArmature::ShaderArmature(){
    
    
}
ShaderArmature::~ShaderArmature(){
    
}
bool ShaderArmature::init(const std::string& name)
{
    return Armature::init(name);
}
ShaderArmature *ShaderArmature::create(const std::string& name)
{
    ShaderArmature *armature = new ShaderArmature;
    if (armature && armature->init(name))
    {
        armature->autorelease();
        return armature;
    }else{
        CC_SAFE_DELETE(armature);
        return nullptr;
    }
}

void ShaderArmature::initShader(bool shaderState){
    
    for (auto& object : _children)
    {
        if (Bone *bone = dynamic_cast<Bone *>(object))
        {
            Node *node = bone->getDisplayRenderNode();
            
            if (nullptr == node)
                continue;
            
            
            Skin *skin = static_cast<Skin *>(node);
            ///-----addCustome shader
            if(shaderState){
                
                auto program = new GLProgram();
                program->initWithByteArrays(vertSource, fragSource);
                
                skin->setGLProgram(program);
                
                program->autorelease();
                
                CHECK_GL_ERROR_DEBUG();
                
                program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
                program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
                program->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
                
                CHECK_GL_ERROR_DEBUG();
                
                program->link();
                
                CHECK_GL_ERROR_DEBUG();
                
                program->updateUniforms();
                
                CHECK_GL_ERROR_DEBUG();
                
            }else{//addNormal shader
                skin->setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));
            }
        }
        
    }
}
void ShaderArmature::draw(Renderer *renderer, const Mat4 &transform, bool transformUpdated)
{
    
    Armature::draw(renderer, transform, transformUpdated);
}

void ShaderArmature::setIceState(){
    _fragSourceFile ="IceShader.fsh";
    _vertSourceFile ="IceShader.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}

void ShaderArmature::setUsuaState(){
    initShader(false);
}

void ShaderArmature::setblurState(){
    _fragSourceFile ="Blur.fsh";
    _vertSourceFile ="Blur.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}

void ShaderArmature::setbanishState(){
    _fragSourceFile ="BanishShader.fsh";
    _vertSourceFile ="BanishShader.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}

void ShaderArmature::setfrozenState(){
    _fragSourceFile ="FrozenShader.fsh";
    _vertSourceFile ="FrozenShader.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}
void ShaderArmature::setgrayState(){
    _fragSourceFile ="GrayScalingShader.fsh";
    _vertSourceFile ="GrayScalingShader.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}
void ShaderArmature::setinvisState(){
    _fragSourceFile ="InvisibleShader.fsh";
    _vertSourceFile ="InvisibleShader.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}
void ShaderArmature::setmirrorState(){
    _fragSourceFile ="MirrorShader.fsh";
    _vertSourceFile ="MirrorShader.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}
void ShaderArmature::setpoisonState(){
    _fragSourceFile ="PoisonShader.fsh";
    _vertSourceFile ="PoisonShader.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}

void ShaderArmature::setstoneState(){
    _fragSourceFile ="StoneShader.fsh";
    _vertSourceFile ="StoneShader.vsh";
    fragSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_fragSourceFile).c_str())->getCString();
    
    vertSource = (GLchar*) __String::createWithContentsOfFile(
                                                            FileUtils::getInstance()->fullPathForFilename(_vertSourceFile).c_str())->getCString();
    initShader(true);
}