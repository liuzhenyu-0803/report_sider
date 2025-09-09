#include "UnitImageGroup.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

UnitImageGroup::UnitImageGroup(QWidget *parent)
    : UnitGroup(parent)
{
    setGroupTitle(tr("ImageName"));
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