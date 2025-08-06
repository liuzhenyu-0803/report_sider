#include "ContentWidget.h"
#include "FlowLayout.h"
#include "views/elements/Element.h"
#include "view_models/ImageElementViewModel.h"

ContentWidget::ContentWidget(QWidget *parent)
    : QWidget(parent), m_layout(nullptr) {
    setupUI();
}

ContentWidget::~ContentWidget() {
    // 清理ViewModels
    qDeleteAll(m_viewModels);
    m_viewModels.clear();
    
    // Elements会由布局管理器自动清理
    m_elements.clear();
}

void ContentWidget::setupUI() {
    setStyleSheet("background-color: #f0f0f0;");
    
    // 创建流布局
    m_layout = new FlowLayout(this, 10, 10, 10); // 边距10，水平间距10，垂直间距10
    setLayout(m_layout);
    
    // 创建5个ImageElementViewModel实例
    for (int i = 0; i < 5; ++i) {
        ImageElementViewModel *viewModel = new ImageElementViewModel(this);
        m_viewModels.append(viewModel);
        
        // 创建Element并传入ViewModel
        Element *element = new Element(viewModel);
        m_elements.append(element);
        
        // 添加到布局中
        m_layout->addWidget(element);
    }
}