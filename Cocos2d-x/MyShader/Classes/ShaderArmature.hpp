//
//  ShaderArmature.hpp
//  MyShader
//
//  Created by QuFangliu on 16/7/9.
//
//

#ifndef ShaderArmature_hpp
#define ShaderArmature_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocostudio;

class ShaderArmature : public cocostudio::Armature
{
public:
    ShaderArmature();
    virtual ~ShaderArmature();
    
    bool init(const std::string& name);
    
    static ShaderArmature *create(const std::string& name) ;
    
    virtual void initShader(bool shaderState);
    //    void setBackgroundNotification();
    
    virtual void draw(Renderer *renderer, const Mat4 &transform, bool transformUpdated);
    //    void listenBackToForeground(Ref *obj);
    void setIceState();
    void setUsuaState();
    
    void setblurState();
    void setbanishState();
    void setfrozenState();
    void setgrayState();
    void setinvisState();
    void setmirrorState();
    void setpoisonState();
    void setstoneState();
protected:
    std::string _fragSourceFile;
    std::string _vertSourceFile;
    GLchar * fragSource;
    GLchar * vertSource;
};

#endif /* ShaderArmature_hpp */
