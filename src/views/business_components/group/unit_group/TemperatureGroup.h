#ifndef UNIT_TEMPERATUREGROUPFRAME_H
#define UNIT_TEMPERATUREGROUPFRAME_H

#include "UnitGroup.h"
#include "views/business_components/draggable/unit_draggable/TemperatureResultDraggable.h"
#include "views/business_components/draggable/unit_draggable/TemperatureParametersDraggable.h"
#include <QList>

class TemperatureGroup : public UnitGroup
{
    Q_OBJECT

public:
    explicit TemperatureGroup(QWidget *parent = nullptr);
    virtual ~TemperatureGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    QList<TemperatureResultDraggable *> m_temperatureResultElements;
    QList<TemperatureParametersDraggable *> m_temperatureParametersElements;
};

#endif // TEMPERATUREGROUP_H
