#include "ContentWidget.h"
#include "thermal_image_index/ThermalImageIndex.h"
#include "tab/Tab.h"

ContentWidget::ContentWidget(QWidget *parent)
    : QWidget(parent)
{
    initUI();
}

ContentWidget::~ContentWidget()
{
    
}

void ContentWidget::initUI() 
{    
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0, 16, 0, 4); 
    m_layout->setSpacing(12);
    setLayout(m_layout);
    
    m_thermalImageIndex = new ThermalImageIndex(this);
    m_layout->addWidget(m_thermalImageIndex);
    
    m_tab = new Tab(this);
    m_tab->setSizePolicy(QSizePolicy::QSizePolicy::Preferred, QSizePolicy::Policy::Expanding);
    m_layout->addWidget(m_tab);
}