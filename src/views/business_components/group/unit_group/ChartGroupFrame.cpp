#include "ChartGroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

ChartGroupFrame::ChartGroupFrame(QWidget *parent)
    : UnitGroupFrame(parent)
{
    // 初始化ChartGroupFrame
    // 设置组标题
    setGroupTitle("Chart Group");
}

ChartGroupFrame::~ChartGroupFrame()
{
    // 析构函数
}

QList<QWidget*> ChartGroupFrame::getElements()
{
    // 直接创建并返回元素列表
    QList<QWidget*> elements;
    elements.append(new TemperatureHistogramElement(this));
    elements.append(new LineTemperatureCurveElement(this));
    return elements;
}