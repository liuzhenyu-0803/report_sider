#ifndef CHARTGROUPFRAME_H
#define CHARTGROUPFRAME_H

#include "../UnitGroupFrame.h"
#include "../../element/unit_element/TemperatureHistogramElement.h"
#include "../../element/unit_element/LineTemperatureCurveElement.h"
#include <QList>

class ChartGroupFrame : public UnitGroupFrame
{
    Q_OBJECT

public:
    explicit ChartGroupFrame(QWidget *parent = nullptr);
    virtual ~ChartGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    QList<TemperatureHistogramElement *> m_temperatureHistogramElements;
    QList<LineTemperatureCurveElement *> m_lineTemperatureCurveElements;
};

#endif // CHARTGROUPFRAME_H