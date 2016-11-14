//
//  TestSampleSprite.cpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/30.
//
//

#include "TestSampleSprite.hpp"

USING_NS_CC;

#define Test_Image_Path     "Image/TestIcon.png"
//#define Test_Image_Path     "Image/example/snowflake.png"
#define Default_vsh_Path    "Shader/default.vert"

#define Sprite_Name         "TestSprite"

#define Interval_Width      200
#define Interval_Height     200

TestSampleSprite::TestSampleSprite()
{
    
}

TestSampleSprite::~TestSampleSprite()
{
    
}

void TestSampleSprite::enterTest()
{
    this->addItems();   //添加测试内容
}

void TestSampleSprite::addItems()
{
    //加一个绿色背景
    auto pLayer = QFL_HELPER->getColorfulLayer(Color4B(0x88, 0xdb, 0xfa, 255));
    this->addChild(pLayer);
    
    //菜单
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //菜单项
    std::vector<std::string> vectorItems;
    vectorItems.push_back("outline");
    vectorItems.push_back("noise");
    
    
    for (int i = 0; i < vectorItems.size(); i++) {
        auto pItem = MenuItemFont::create(vectorItems[i], [=](Ref*){
            this->showTest(vectorItems[i]);
        });
        pItem->setPosition(Vec2(100, SCREEN_TOP - 50.0 - i * 40));
        pMenu->addChild(pItem);
    }
    
    //默认显示一项
    if (vectorItems.size() > 0) {
        this->showTest(vectorItems[0]);
    }
    else {}
}

void TestSampleSprite::showTest(const std::string &strName)
{
    if (strName == "outline") {
        //生成Sprite
        auto pOutlineSprite = this->replaceOrCreateTestSprite();
        
        //添加GLProgramState
        auto pOutlineState = this->getGLProgrameState("", "Shader/example/outline.fsh");
        pOutlineSprite->setGLProgramState(pOutlineState);
        
        //设置全局变量
        Vec3 vecColor(1.0f, 0.2f, 0.3f);
        GLfloat radius = 0.01f; //这里实际是图片size的比例
        GLfloat threshold = 1.75;   //实际用来调节亮度
        
        pOutlineState->setUniformVec3("u_outlineColor", vecColor);
        pOutlineState->setUniformFloat("u_radius", radius);
        pOutlineState->setUniformFloat("u_threshold", threshold);
    }
    else if (strName == "noise") {
        //生成Sprite
        auto pNoise = this->replaceOrCreateTestSprite();
        
        //添加GLProgramState
        auto pNoiseState = this->getGLProgrameState("", "Shader/example/noise.fsh");
        pNoise->setGLProgramState(pNoiseState);
        
        pNoiseState->setUniformFloat("u_intensity", 0.05);
        pNoiseState->setUniformVec2("u_resolution", Vec2(pNoise->getContentSize().width, pNoise->getContentSize().height));
    }
    else {
        log("Can not found testing %s.", strName.c_str());
    }
}

//工具一类
std::string TestSampleSprite::getStringFromFile(const std::string &strName)
{
    auto fullPath = FileUtils::getInstance()->fullPathForFilename(strName);
    return FileUtils::getInstance()->getStringFromFile(fullPath);
}

cocos2d::Sprite* TestSampleSprite::replaceOrCreateTestSprite()
{
    //清除旧的
    if (this->getChildByName(Sprite_Name)) {
        this->removeChildByName(Sprite_Name);
    }
    else {}
    //添加新的
    auto pTestSprite = Sprite::create(Test_Image_Path);
    pTestSprite->setPosition(SCREEN_CENTER);
    this->addChild(pTestSprite);
    
    //返回
    return pTestSprite;
}

//根据file获得一个GLProgramState
cocos2d::GLProgramState* TestSampleSprite::getGLProgrameState(const std::string &vshName, const std::string &fshName)
{
    //处理一下vsh的name
    std::string strVshName = vshName.empty() ? Default_vsh_Path : vshName;
    
    //获得vsh和fsh的string
    auto strVsh = FileUtils::getInstance()->getStringFromFile(FileUtils::getInstance()->fullPathForFilename(strVshName));
    auto strFsh = FileUtils::getInstance()->getStringFromFile(FileUtils::getInstance()->fullPathForFilename(fshName));
    
    auto glProgram = GLProgram::createWithFilenames(strVshName, fshName);   //两种方式生成GLProgram
//    auto glProgram = GLProgram::createWithByteArrays(strVsh.c_str(), strFsh.c_str());
    return GLProgramState::getOrCreateWithGLProgram(glProgram);
}
