#include "TemperatureUnitFieldGroup.h"

#include "views/business_components/sub_group/field_sub_group/TemperatureResultSubGroupFrame.h"
#include "views/business_components/sub_group/field_sub_group/TemperatureParametersSubGroupFrame.h"
#include "views/business_components/sub_group/field_sub_group/TemperatureAreaSubGroupFrame.h"

TemperatureUnitFieldGroup::TemperatureUnitFieldGroup(QWidget *parent)
    : FieldGroupFrame(parent)
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
    TemperatureResultSubGroupFrame *resultSubGroup = new TemperatureResultSubGroupFrame(this);
    m_subGroups.append(resultSubGroup);
    
    // 创建测温参数子组
    TemperatureParametersSubGroupFrame *parametersSubGroup = new TemperatureParametersSubGroupFrame(this);
    m_subGroups.append(parametersSubGroup);
    
    // 创建测温面积子组
    TemperatureAreaSubGroupFrame *areaSubGroup = new TemperatureAreaSubGroupFrame(this);
    m_subGroups.append(areaSubGroup);
}

QList<QWidget*> TemperatureUnitFieldGroup::getElements()
{
    return m_subGroups;
}