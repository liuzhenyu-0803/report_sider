#include "TemperatureGroup.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

TemperatureGroup::TemperatureGroup(QWidget *parent)
    : UnitGroup(parent)
{
    // 初始化TemperatureGroupFrame
    // 设置组标题
    setGroupTitle("Temperature Group");
}

TemperatureGroup::~TemperatureGroup()
{
    // 析构函数
}

QList<QWidget*> TemperatureGroup::getElements()
{
    // 直接创建并返回元素列表
    QList<QWidget*> elements;
    elements.append(new TemperatureResultDraggable(this));
    elements.append(new TemperatureParametersDraggable(this));
    return elements;
}