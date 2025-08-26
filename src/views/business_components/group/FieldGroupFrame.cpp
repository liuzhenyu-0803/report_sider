#include "FieldGroupFrame.h"
#include <QVBoxLayout>

FieldGroupFrame::FieldGroupFrame(QWidget *parent)
    : GroupFrame(parent)
{
    // 设置组标题
    setGroupTitle("Field Group");
}

FieldGroupFrame::~FieldGroupFrame()
{
}

void FieldGroupFrame::loadElements()
{
    // 获取基类的contentWidget
    QWidget *contentWidget = getContentWidget();
    if (!contentWidget) return;
    
    // 获取子类提供的元素列表
    QList<ElementFrame*> elements = getElements();
    
    // 创建垂直布局用于放置元素
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 5, 10, 10);
    layout->setSpacing(10);
    
    // 将元素添加到垂直布局中
    for (ElementFrame *element : elements) {
        layout->addWidget(element);
    }
    
    // 添加伸展因子以使元素靠上对齐
    layout->addStretch();
    
    // 将布局设置到基类的contentWidget
    contentWidget->setLayout(layout);
}
