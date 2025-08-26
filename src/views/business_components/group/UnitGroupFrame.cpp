#include "UnitGroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

UnitGroupFrame::UnitGroupFrame(QWidget *parent)
    : GroupFrame(parent)
{
    // 设置组标题
    setGroupTitle("Unit Group");
}

UnitGroupFrame::~UnitGroupFrame()
{
}

void UnitGroupFrame::loadElements()
{
    // 获取基类的contentWidget
    QWidget *contentWidget = getContentWidget();
    if (!contentWidget) return;
    
    // 获取子类提供的元素列表
    QList<ElementFrame*> elements = getElements();
    
    // 创建流布局用于放置元素
    FlowLayout *layout = new FlowLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(8);
    
    // 将元素添加到流布局中
    for (ElementFrame *element : elements) {
        layout->addWidget(element);
    }
    
    // 将布局设置到基类的contentWidget
    contentWidget->setLayout(layout);
}
