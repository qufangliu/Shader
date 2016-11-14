//
//  QFLTestSprite.cpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/30.
//
//

#include "QFLTestSprite.hpp"

USING_NS_CC;

#define Test_Image_Path     "Image/TestIcon.png"
#define Default_vsh_Path    "Shader/default.vert"

#define Sprite_Name         "TestSprite"

QFLTestSprite::QFLTestSprite()
{
    
}

QFLTestSprite::~QFLTestSprite()
{
    
}

void QFLTestSprite::enterTest()
{
    this->addMenu();
}

void QFLTestSprite::addMenu()
{
    //添加一个有色背景
    auto pLayer = QFL_HELPER->getColorfulLayer(Color4B(0x2f, 0xa9, 0x26, 255));
    this->addChild(pLayer);
    
    //添加菜单
    auto pMenu = Menu::create();
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
    
    //录入测试项
    std::vector<std::string> vectorItems;
    vectorItems.push_back("Noise");
    vectorItems.push_back("Tile");
    
    
    //生成按钮
    for (int i = 0; i < vectorItems.size(); i++) {
        auto pItem = MenuItemFont::create(vectorItems[i], [=](Ref*){
            this->showTestItem(vectorItems[i]);
        });
        pItem->setPosition(Vec2(100.0, SCREEN_TOP - 50.0 - i * 40.0));
        pMenu->addChild(pItem);
    }
}

void QFLTestSprite::showTestItem(const std::string &strTestName)
{
    if (strTestName == "Noise") {
        auto pSprite = this->replaceOrCreateSprite();
        auto pState = this->getGLProgramState("", "Shader/myshader/Noise.fsh");
        pSprite->setGLProgramState(pState);
        
        //设置属性
        pState->setUniformFloat("u_ratio", 0.3);
        
        //TODO:未完成noise算法
    }
    else if (strTestName == "Tile") {
        //清除旧的
        if (this->getChildByName(Sprite_Name)) {
            this->removeChildByName(Sprite_Name);
        }
        else {}
        //添加新的
        auto pTile = Sprite::create("Image/test_1/tile.png");
        pTile->setPosition(SCREEN_CENTER);
        pTile->setName(Sprite_Name);
        this->addChild(pTile);
        //设置shader
        auto pState = this->getGLProgramState("", "Shader/myshader/Tile.fsh");
        pTile->setGLProgramState(pState);
        //属性
        pState->setUniformVec2("u_size", Vec2(400, 400));
        pState->setUniformVec2("u_sizeTile", Vec2(pTile->getContentSize().width, pTile->getContentSize().height));
    }
    else {
        log("Can not found testing %s", strTestName.c_str());
    }
}

cocos2d::Sprite* QFLTestSprite::replaceOrCreateSprite()
{
    //清除旧的
    if (this->getChildByName(Sprite_Name)) {
        this->removeChildByName(Sprite_Name);
    }
    else {}
    //添加新的
    auto pTestSprite = Sprite::create(Test_Image_Path);
    pTestSprite->setPosition(SCREEN_CENTER);
    pTestSprite->setName(Sprite_Name);
    this->addChild(pTestSprite);
    
    //返回
    return pTestSprite;
}

cocos2d::GLProgramState* QFLTestSprite::getGLProgramState(const std::string &strVshName, const std::string &strFshName)
{
    //检查文件名
    std::string strCheckedVshName = strVshName.empty() ? Default_vsh_Path : strVshName;
    //生成GLProgram
    auto glProgram = GLProgram::createWithFilenames(strCheckedVshName, strFshName);
    //生成GLProgramState
    return GLProgramState::getOrCreateWithGLProgram(glProgram);
}
