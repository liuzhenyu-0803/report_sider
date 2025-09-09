#include "ChartGroup.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

ChartGroup::ChartGroup(QWidget *parent)
    : UnitGroup(parent)
{
    // 初始化ChartGroupFrame
    // 设置组标题
    setGroupTitle(tr("ChartName"));
}

ChartGroup::~ChartGroup()
{
    // 析构函数
}

QList<QWidget*> ChartGroup::getElements()
{
    // 直接创建并返回元素列表
    QList<QWidget*> elements;
    elements.append(new TemperatureHistogramDraggable(this));
    elements.append(new LineTemperatureCurveDraggable(this));
    return elements;
}