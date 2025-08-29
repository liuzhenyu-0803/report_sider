#include "ImagePropertyGroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

ImagePropertyGroupFrame::ImagePropertyGroupFrame(QWidget *parent)
    : UnitGroupFrame(parent)
{
    // 初始化ImagePropertyGroupFrame
    // 设置组标题
    setGroupTitle("Image Property Group");
}

ImagePropertyGroupFrame::~ImagePropertyGroupFrame()
{
    // 析构函数
}

QList<QWidget*> ImagePropertyGroupFrame::getElements()
{
    // 直接创建并返回元素列表
    QList<QWidget*> elements;
    elements.append(new ImageInfoElement(this));
    elements.append(new InstrumentInfoElement(this));
    return elements;
}