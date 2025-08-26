#ifndef UNITGROUPFRAME_H
#define UNITGROUPFRAME_H

#include "GroupFrame.h"
#include "views/business_components/element/UnitElementFrame.h"
#include "views/business_components/element/unit_element/ThermalImageElement.h"
#include "views/common_components/FlowLayout.h"
#include <QList>

class UnitGroupFrame : public GroupFrame
{
    Q_OBJECT

public:
    explicit UnitGroupFrame(QWidget *parent = nullptr);
    virtual ~UnitGroupFrame();

    // 实现基类虚接口函数
    virtual void loadElements() override;
};

#endif // UNITGROUPFRAME_H