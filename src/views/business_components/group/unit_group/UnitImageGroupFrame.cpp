#include "UnitImageGroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

UnitImageGroupFrame::UnitImageGroupFrame(QWidget *parent)
    : UnitGroupFrame(parent)
{
    // 初始化UnitImageGroupFrame
    // 设置组标题
    setGroupTitle("Image Group");
}

UnitImageGroupFrame::~UnitImageGroupFrame()
{
    // 析构函数
}

QList<QWidget*> UnitImageGroupFrame::getElements()
{
    // 直接创建并返回元素列表
    QList<QWidget*> elements;
    elements.append(new ThermalImageElement(this));
    elements.append(new VisibleLightElement(this));
    elements.append(new NormalImageElement(this));
    return elements;
}