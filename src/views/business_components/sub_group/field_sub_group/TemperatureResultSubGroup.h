#ifndef TEMPERATURERESULTSUBGROUP_H
#define TEMPERATURERESULTSUBGROUP_H

#include "FieldSubGroup.h"

class TemperatureResultSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TemperatureResultSubGroup(QWidget *parent = nullptr);
    virtual ~TemperatureResultSubGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TEMPERATURERESULTSUBGROUP_H
