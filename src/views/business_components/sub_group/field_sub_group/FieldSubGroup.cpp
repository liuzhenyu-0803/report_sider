#include "FieldSubGroup.h"
#include <QVBoxLayout>

FieldSubGroup::FieldSubGroup(QWidget *parent)
    : SubGroup(parent)
{
    // 设置组标题
    setGroupTitle("Field SubGroup");
}

FieldSubGroup::~FieldSubGroup()
{
}

void FieldSubGroup::loadElements()
{
    // 获取基类的contentWidget
    QWidget *contentWidget = getContentWidget();
    if (!contentWidget) return;
    
    // 获取子类提供的元素列表
    QList<QWidget*> elements = getElements();
    
    // 创建垂直布局用于放置元素
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(10);
    
    // 将元素添加到垂直布局中
    for (QWidget *element : elements) {
        layout->addWidget(element);
    }
    
    // 将布局设置到基类的contentWidget
    contentWidget->setLayout(layout);
}
