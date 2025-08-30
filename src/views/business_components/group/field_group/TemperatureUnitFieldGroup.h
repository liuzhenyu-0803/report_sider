#ifndef FIELD_TEMPERATUREUNITGROUPFRAME_H
#define FIELD_TEMPERATUREUNITGROUPFRAME_H

#include "FieldGroup.h"

class TemperatureUnitFieldGroup : public FieldGroup
{
    Q_OBJECT

public:
    explicit TemperatureUnitFieldGroup(QWidget *parent = nullptr);
    virtual ~TemperatureUnitFieldGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;
    
protected:
    virtual void createSubGroups();
    
private:
    QList<QWidget*> m_subGroups;
};

#endif // TEMPERATUREUNITGROUPFRAME_H