//
//  QFLTestTIle.hpp
//  MyShaderList
//
//  Created by QuFangliu on 2016/10/23.
//
//

#ifndef QFLTestTIle_hpp
#define QFLTestTIle_hpp

#include <stdio.h>
#include "QFLTestItem/QFLLayerBase.hpp"

class QFLTestTile : public QFLLayerBase
{
CC_CONSTRUCTOR_ACCESS:
    QFLTestTile();
    virtual ~QFLTestTile();
    CREATE_FUNC(QFLTestTile);
    
public:
    virtual void enterTest() override;
    
private:
    void addUI();
};

#endif /* QFLTestTIle_hpp */
