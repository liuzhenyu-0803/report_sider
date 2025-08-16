#include "ContentWidget.h"
#include "ThermalImageIndex.h"
#include "TabFrame.h"

ContentWidget::ContentWidget(QWidget *parent)
    : QWidget(parent), m_layout(nullptr), m_thermalImageIndex(nullptr), m_tabFrame(nullptr) {
    setupUI();
}

ContentWidget::~ContentWidget() {
    // 析构函数现在为空，因为Qt对象会由父对象自动清理
}

void ContentWidget::setupUI() {
    setStyleSheet("background-color: #f0f0f0;");
    
    // 创建垂直布局
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(10, 10, 10, 10); // 设置边距
    m_layout->setSpacing(10); // 设置控件间距
    setLayout(m_layout);
    
    // 创建ThermalImageIndex组件
    m_thermalImageIndex = new ThermalImageIndex(this);
    m_layout->addWidget(m_thermalImageIndex);
    
    // 创建TabFrame组件
    m_tabFrame = new TabFrame(this);
    m_layout->addWidget(m_tabFrame);
    
    // 添加弹性空间，使组件在垂直方向上靠上对齐
    m_layout->addStretch();
}