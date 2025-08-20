#include "FieldGroupFrame.h"
#include <QVBoxLayout>

FieldGroupFrame::FieldGroupFrame(QWidget *parent)
    : GroupFrame(parent)
{
    // 初始化FieldGroupFrame
    // 添加一些示例元素
    for (int i = 0; i < 3; ++i) {
        FieldElement *element = new FieldElement(this);
        m_fieldElements.append(element);
    }
    
    // 设置组标题
    setGroupTitle("Field Group");
}

FieldGroupFrame::~FieldGroupFrame()
{
    // 清理资源
    qDeleteAll(m_fieldElements);
}

void FieldGroupFrame::loadData()
{
    // 创建垂直布局用于放置元素
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(10, 5, 10, 10);
    layout->setSpacing(10);
    
    // 将元素添加到垂直布局中
    for (FieldElement *element : m_fieldElements) {
        layout->addWidget(element);
    }
    
    // 添加伸展因子以使元素靠上对齐
    layout->addStretch();
    
    // 创建一个容器widget来容纳垂直布局
    QWidget *container = new QWidget(this);
    container->setLayout(layout);
    
    // 获取主布局并添加内容区域
    QVBoxLayout *mainLayout = static_cast<QVBoxLayout*>(this->layout());
    if (mainLayout) {
        mainLayout->addWidget(container);
    }
}