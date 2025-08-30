#include "TemperatureUnitFieldGroup.h"

#include "views/business_components/sub_group/field_sub_group/TemperatureResultSubGroup.h"
#include "views/business_components/sub_group/field_sub_group/TemperatureParametersSubGroup.h"
#include "views/business_components/sub_group/field_sub_group/TemperatureAreaSubGroup.h"

TemperatureUnitFieldGroup::TemperatureUnitFieldGroup(QWidget *parent)
    : FieldGroup(parent)
{
    setGroupTitle("测温单元");

    createSubGroups();
}

TemperatureUnitFieldGroup::~TemperatureUnitFieldGroup()
{
}

void TemperatureUnitFieldGroup::createSubGroups()
{
    // 创建测温结果子组
    TemperatureResultSubGroup *resultSubGroup = new TemperatureResultSubGroup(this);
    m_subGroups.append(resultSubGroup);
    
    // 创建测温参数子组
    TemperatureParametersSubGroup *parametersSubGroup = new TemperatureParametersSubGroup(this);
    m_subGroups.append(parametersSubGroup);
    
    // 创建测温面积子组
    TemperatureAreaSubGroup *areaSubGroup = new TemperatureAreaSubGroup(this);
    m_subGroups.append(areaSubGroup);
}

QList<QWidget*> TemperatureUnitFieldGroup::getElements()
{
    return m_subGroups;
}