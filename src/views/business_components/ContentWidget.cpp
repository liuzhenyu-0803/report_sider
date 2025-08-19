#include "ContentWidget.h"
#include "ThermalImageIndex.h"
#include "TabFrame.h"

ContentWidget::ContentWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

ContentWidget::~ContentWidget()
{
    
}

void ContentWidget::setupUI() 
{    
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0, 15, 0, 15); 
    m_layout->setSpacing(12);
    setLayout(m_layout);
    
    m_thermalImageIndex = new ThermalImageIndex(this);
    m_layout->addWidget(m_thermalImageIndex);
    
    m_tabFrame = new TabFrame(this);
    m_tabFrame->setSizePolicy(QSizePolicy::QSizePolicy::Preferred, QSizePolicy::Policy::Expanding);
    m_layout->addWidget(m_tabFrame);
}