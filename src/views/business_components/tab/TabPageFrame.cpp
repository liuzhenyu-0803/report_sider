#include "TabPageFrame.h"
#include "views/business_components/group/GroupFrame.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>

TabPageFrame::TabPageFrame(QWidget *parent)
    : QFrame(parent)
{
    setupUI();
}

TabPageFrame::~TabPageFrame()
{
}

void TabPageFrame::setupUI() {
    // 创建主布局
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(16, 16, 16, 0);
    m_mainLayout->setSpacing(0);
    
    // 创建滚动区域
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    // 创建内容部件和布局
    m_contentWidget = new QWidget();
    
    m_scrollArea->setWidget(m_contentWidget);
    m_mainLayout->addWidget(m_scrollArea);
    
    setLayout(m_mainLayout);
}