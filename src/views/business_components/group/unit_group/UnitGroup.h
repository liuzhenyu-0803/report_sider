#ifndef UNITGROUP_H
#define UNITGROUP_H

#include "views/business_components/group/Group.h"
#include "views/business_components/draggable/unit_draggable/UnitDraggable.h"
#include "views/business_components/draggable/unit_draggable/ThermalImageDraggable.h"
#include "views/common_components/FlowLayout.h"
#include <QList>

class UnitGroup : public Group
{
    Q_OBJECT

public:
    explicit UnitGroup(QWidget *parent = nullptr);
    virtual ~UnitGroup();

    // 实现基类虚接口函数
    virtual void loadContent() override;
    virtual QList<QWidget*> getContentWidgets() override;
    
    // 子类需要实现的虚函数
    virtual QList<QWidget*> getElements() = 0;
};

#endif // UNITGROUP_H