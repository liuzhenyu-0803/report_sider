#include "ContentWidget.h"
#include "FlowLayout.h"
#include "elements/Element.h"
#include "elements/ImageElement.h"
#include "elements/HtmlElement.h"
#include "elements/UrlsElement.h"
#include "../view_models/ImageElementViewModel.h"
#include "../view_models/HtmlElementViewModel.h"
#include "../view_models/UrlsElementViewModel.h"

ContentWidget::ContentWidget(QWidget *parent)
    : QWidget(parent), m_layout(nullptr) {
    setupUI();
}

ContentWidget::~ContentWidget() {
    // 清理ViewModels
    qDeleteAll(m_imageViewModels);
    m_imageViewModels.clear();
    
    qDeleteAll(m_htmlViewModels);
    m_htmlViewModels.clear();
    
    qDeleteAll(m_urlsViewModels);
    m_urlsViewModels.clear();
    
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
        m_imageViewModels.append(viewModel);
        
        // 创建ImageElement并传入ViewModel
        ImageElement *element = new ImageElement(viewModel);
        m_elements.append(element);
        
        // 添加到布局中
        m_layout->addWidget(element);
    }
    
    // 创建2个HtmlElementViewModel实例
    for (int i = 0; i < 2; ++i) {
        HtmlElementViewModel *viewModel = new HtmlElementViewModel(this);
        m_htmlViewModels.append(viewModel);
        
        // 创建HtmlElement并传入ViewModel
        HtmlElement *element = new HtmlElement(viewModel);
        m_elements.append(element);
        
        // 添加到布局中
        m_layout->addWidget(element);
    }
    
    // 创建3个UrlsElementViewModel实例
    for (int i = 0; i < 3; ++i) {
        UrlsElementViewModel *viewModel = new UrlsElementViewModel(this);
        m_urlsViewModels.append(viewModel);
        
        // 创建UrlsElement并传入ViewModel
        UrlsElement *element = new UrlsElement(viewModel);
        m_elements.append(element);
        
        // 添加到布局中
        m_layout->addWidget(element);
    }
}