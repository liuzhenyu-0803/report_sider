#include "UnitGroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

UnitGroupFrame::UnitGroupFrame(QWidget *parent)
    : GroupFrame(parent)
{
    // 初始化UnitGroupFrame
    // 添加一些示例元素
    for (int i = 0; i < 3; ++i) {
        UnitElement *element = new UnitElement(this);
        m_unitElements.append(element);
    }
    
    // 设置组标题
    setGroupTitle("Unit Group");
}

UnitGroupFrame::~UnitGroupFrame()
{
    // 清理资源
    qDeleteAll(m_unitElements);
}

void UnitGroupFrame::loadData()
{
    // 创建流布局用于放置元素
    FlowLayout *layout = new FlowLayout();
    layout->setContentsMargins(10, 5, 10, 10);
    layout->setSpacing(10);
    
    // 将元素添加到流布局中
    for (UnitElement *element : m_unitElements) {
        layout->addWidget(element);
    }
    
    // 创建一个容器widget来容纳流布局
    QWidget *container = new QWidget(this);
    container->setLayout(layout);
    
    // 获取主布局并添加内容区域
    QVBoxLayout *mainLayout = static_cast<QVBoxLayout*>(this->layout());
    if (mainLayout) {
        mainLayout->addWidget(container);
    }
}