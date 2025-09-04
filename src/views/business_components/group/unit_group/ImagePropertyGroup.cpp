#include "ImagePropertyGroup.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

ImagePropertyGroup::ImagePropertyGroup(QWidget *parent)
    : UnitGroup(parent)
{
    // 初始化ImagePropertyGroupFrame
    // 设置组标�?
    setGroupTitle("Image Property Group");
}

ImagePropertyGroup::~ImagePropertyGroup()
{
    // 析构函数
}

QList<QWidget*> ImagePropertyGroup::getElements()
{
    // 直接创建并返回元素列�?
    QList<QWidget*> elements;
    elements.append(new ImageInfoDraggable(this));
    elements.append(new InstrumentInfoDraggable(this));
    elements.append(new GeographicInfoDraggable(this));
    return elements;
}