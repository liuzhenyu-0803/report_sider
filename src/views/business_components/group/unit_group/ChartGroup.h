#ifndef CHARTGROUP_H
#define CHARTGROUP_H

#include "UnitGroup.h"
#include "views/business_components/draggable/unit_draggable/TemperatureHistogramDraggable.h"
#include "views/business_components/draggable/unit_draggable/LineTemperatureCurveDraggable.h"
#include <QList>

class ChartGroup : public UnitGroup
{
    Q_OBJECT

public:
    explicit ChartGroup(QWidget *parent = nullptr);
    virtual ~ChartGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    QList<TemperatureHistogramDraggable *> m_temperatureHistogramElements;
    QList<LineTemperatureCurveDraggable *> m_lineTemperatureCurveElements;
};

#endif // CHARTGROUP_H
