#include "Group.h"
#include "QcApplication.h"
#include "views/common_components/FlowLayout.h"
#include "views/business_components/draggable/Draggable.h"
#include "QcLabel.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>
#include <QWidget>

Group::Group(QWidget *parent)
    : QFrame(parent)
{
    setupUI();

    PostTaskToMainThread([this]() {
        loadContent();
    });
}

Group::~Group()
{
}

void Group::setupUI() 
{
    // 创建主布局
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(6);

    // 创建标题栏容器
    m_titleBar = new QWidget(this);

    // 创建标题栏布局
    m_titleLayout = new QHBoxLayout(m_titleBar);
    m_titleLayout->setContentsMargins(0, 0, 0, 0);
    m_titleLayout->setSpacing(6);

    // 创建组标题标签
    m_groupLabel = new MicroUI::QcLabel(this);
    QFont font;
    font.setPixelSize(14);
    font.setBold(true);
    m_groupLabel->setFont(font);
    m_groupLabel->setTextColorParams("#000000, 0.7");
    m_groupLabel->setText("Group");
    
    // 创建切换按钮
    m_iconLabel = new MicroUI::QcLabel(this);
    m_iconLabel->setFixedSize(20, 20);
    m_iconLabel->SetIconPath(":/images/arrow_down.svg");
    m_iconLabel->SetIconColorParams("#000000, 0.6");

    // 将标签和按钮添加到标题栏布局
    m_titleLayout->addWidget(m_groupLabel);
    m_titleLayout->addStretch();
    m_titleLayout->addWidget(m_iconLabel);
    
    // 将标题栏添加到主布局
    m_mainLayout->addWidget(m_titleBar);
    
    // 创建内容容器widget
    m_contentWidget = new QWidget(this);
    m_mainLayout->addWidget(m_contentWidget);
    
    setLayout(m_mainLayout);
}

void Group::setGroupTitle(const QString &title) 
{
    if (m_groupLabel) 
    {
        m_groupLabel->setText(title);
    }
}

void Group::toggleContent() 
{
    m_isExpanded = !m_isExpanded;
    
    // 切换内容区域的可见�?
    if (m_contentWidget) 
    {
        setUpdatesEnabled(false);
        m_contentWidget->setVisible(m_isExpanded);
        QTimer::singleShot(0, this, [this]() {
            setUpdatesEnabled(true);
        });
    }

    // 更新按钮图标
    if (m_isExpanded)
    {
        m_iconLabel->SetIconPath(":/images/arrow_down.svg");
        // 当group被展开时，发射信号
        emit groupExpanded(this);
    }
    else
    {
        m_iconLabel->SetIconPath(":/images/arrow_up.svg");
    }
}

void Group::setExpanded(bool expanded)
{
    if (m_isExpanded == expanded) {
        return;
    }
    
    m_isExpanded = expanded;
    
    // 更新内容区域的可见性
    if (m_contentWidget)
    {
        setUpdatesEnabled(false);
        m_contentWidget->setVisible(m_isExpanded);
        QTimer::singleShot(0, this, [this]() {
            setUpdatesEnabled(true);
        });
    }

    // 更新按钮图标
    if (m_isExpanded)
    {
        m_iconLabel->SetIconPath(":/images/arrow_down.svg");
    }
    else
    {
        m_iconLabel->SetIconPath(":/images/arrow_up.svg");
    }
}

bool Group::isExpanded() const
{
    return m_isExpanded;
}

QWidget* Group::getContentWidget() const
{
    return m_contentWidget;
}

void Group::mousePressEvent(QMouseEvent *event)
{
    QFrame::mousePressEvent(event);
    if (event->button() == Qt::LeftButton && m_titleBar->underMouse()) 
    {
        toggleContent();
    }
}   