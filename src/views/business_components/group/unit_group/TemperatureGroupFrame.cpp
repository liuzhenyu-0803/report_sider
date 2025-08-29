#include "TemperatureGroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

TemperatureGroupFrame::TemperatureGroupFrame(QWidget *parent)
    : UnitGroupFrame(parent)
{
    // 初始化TemperatureGroupFrame
    // 设置组标题
    setGroupTitle("Temperature Group");
}

TemperatureGroupFrame::~TemperatureGroupFrame()
{
    // 析构函数
}

QList<QWidget*> TemperatureGroupFrame::getElements()
{
    // 直接创建并返回元素列表
    QList<QWidget*> elements;
    elements.append(new TemperatureResultElement(this));
    elements.append(new TemperatureParametersElement(this));
    return elements;
}