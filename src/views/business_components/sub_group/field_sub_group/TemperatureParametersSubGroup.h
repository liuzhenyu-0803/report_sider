#ifndef TEMPERATUREPARAMETERSSUBGROUP_H
#define TEMPERATUREPARAMETERSSUBGROUP_H

#include "FieldSubGroup.h"

class TemperatureParametersSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TemperatureParametersSubGroup(QWidget *parent = nullptr);
    virtual ~TemperatureParametersSubGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TEMPERATUREPARAMETERSSUBGROUP_H
