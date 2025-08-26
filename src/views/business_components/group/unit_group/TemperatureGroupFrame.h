#ifndef TEMPERATUREGROUPFRAME_H
#define TEMPERATUREGROUPFRAME_H

#include "../UnitGroupFrame.h"
#include "views/business_components/element/unit_element/TemperatureResultElement.h"
#include "views/business_components/element/unit_element/TemperatureParametersElement.h"
#include <QList>

class TemperatureGroupFrame : public UnitGroupFrame
{
    Q_OBJECT

public:
    explicit TemperatureGroupFrame(QWidget *parent = nullptr);
    virtual ~TemperatureGroupFrame();

    // 实现基类虚接口函数
    virtual QList<ElementFrame*> getElements() override;

private:
    QList<TemperatureResultElement *> m_temperatureResultElements;
    QList<TemperatureParametersElement *> m_temperatureParametersElements;
};

#endif // TEMPERATUREGROUPFRAME_H