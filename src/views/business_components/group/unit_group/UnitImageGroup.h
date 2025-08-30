#ifndef UNITIMAGEGROUP_H
#define UNITIMAGEGROUP_H

#include "UnitGroup.h"
#include "views/business_components/draggable/unit_draggable/ThermalImageDraggable.h"
#include "views/business_components/draggable/unit_draggable/VisibleLightDraggable.h"
#include "views/business_components/draggable/unit_draggable/NormalImageDraggable.h"
#include <QList>

class UnitImageGroup : public UnitGroup
{
    Q_OBJECT

public:
    explicit UnitImageGroup(QWidget *parent = nullptr);
    virtual ~UnitImageGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    QList<ThermalImageDraggable *> m_thermalImageElements;
    QList<VisibleLightDraggable *> m_visibleLightElements;
    QList<NormalImageDraggable *> m_normalImageElements;
};

#endif // UNITIMAGEGROUP_H
