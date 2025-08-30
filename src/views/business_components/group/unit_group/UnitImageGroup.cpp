#include "UnitImageGroup.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

UnitImageGroup::UnitImageGroup(QWidget *parent)
    : UnitGroup(parent)
{
    // 初始化UnitImageGroupFrame
    // 设置组标题
    setGroupTitle("Image Group");
}

UnitImageGroup::~UnitImageGroup()
{
    // 析构函数
}

QList<QWidget*> UnitImageGroup::getElements()
{
    // 直接创建并返回元素列表
    QList<QWidget*> elements;
    elements.append(new ThermalImageDraggable(this));
    elements.append(new VisibleLightDraggable(this));
    elements.append(new NormalImageDraggable(this));
    return elements;
}