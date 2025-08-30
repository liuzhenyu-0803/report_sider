#ifndef TEMPERATUREAREASUBGROUP_H
#define TEMPERATUREAREASUBGROUP_H

#include "FieldSubGroup.h"

class TemperatureAreaSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TemperatureAreaSubGroup(QWidget *parent = nullptr);
    virtual ~TemperatureAreaSubGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TEMPERATUREAREASUBGROUP_H
