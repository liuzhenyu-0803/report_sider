#include "TabPage.h"
#include "views/business_components/group/Group.h"
#include "QcScrollBar.h"
#include "QcApplication.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>

TabPage::TabPage(QWidget *parent)
    : QFrame(parent)
{
    setupUI();

    PostTaskToMainThread([this]() {
        loadContent();
    });
}

TabPage::~TabPage()
{
}

void TabPage::setupUI() {
    // 创建主布局
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(16, 0, 16, 0);
    m_mainLayout->setSpacing(0);
    
    // 创建滚动区域
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    auto scrollBar = new MicroUI::QcScrollBar(Qt::Orientation::Vertical, this);
    scrollBar->SetOriginalScrollBar(m_scrollArea->verticalScrollBar());

    // 创建内容部件和布局
    m_contentWidget = new QWidget();
    
    m_scrollArea->setWidget(m_contentWidget);
    m_mainLayout->addWidget(m_scrollArea);
    
    setLayout(m_mainLayout);
}