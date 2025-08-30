#include "UnitGroup.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

UnitGroup::UnitGroup(QWidget *parent)
    : Group(parent)
{
    // 设置组标题
    setGroupTitle("Unit Group");
}

UnitGroup::~UnitGroup()
{
}

void UnitGroup::loadContent()
{
    // 获取基类的contentWidget
    QWidget *contentWidget = getContentWidget();
    if (!contentWidget) return;
        
    // 创建流布局用于放置元素
    FlowLayout *layout = new FlowLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(8);
    
    // 将元素添加到流布局中
    for (QWidget *element : getContentWidgets()) {
        layout->addWidget(element);
    }
    
    // 将布局设置到基类的contentWidget
    contentWidget->setLayout(layout);
}

QList<QWidget*> UnitGroup::getContentWidgets()
{
    return getElements();
}
