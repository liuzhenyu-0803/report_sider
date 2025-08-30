#include "SubGroup.h"
#include "views/common_components/FlowLayout.h"
#include "views/business_components/draggable/Draggable.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>
#include <QWidget>

SubGroup::SubGroup(QWidget *parent)
    : QFrame(parent)
    , m_isExpanded(true)
{
    setupUI();
    
    QTimer::singleShot(0, this, [=]{
        // 调用虚接口函数加载数�?
        loadElements();
    });
}

SubGroup::~SubGroup()
{
}

void SubGroup::setupUI() {
    // 创建主布局
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(6);
    
    // 创建标题栏容�?
    QWidget *titleBar = new QWidget(this);
    titleBar->setStyleSheet("background-color: transparent;");
    
    // 创建标题栏布局
    m_titleLayout = new QHBoxLayout(titleBar);
    m_titleLayout->setContentsMargins(0, 0, 0, 0);
    m_titleLayout->setSpacing(5);
    
    // 创建组标�?
    m_groupLabel = new QLabel("SubGroup", this);
    m_groupLabel->setStyleSheet("font-weight: bold; font-size: 14px; margin-top: 5px;");
    
    // 创建切换按钮
    m_iconLabel = new MicroUI::QcLabel(this);
    m_iconLabel->setFixedSize(20, 20);
    m_iconLabel->SetIconPath(":/images/arrow_down.svg");
    m_iconLabel->SetIconColorParams("#000000, 0.9");

    // 将标签和按钮添加到标题栏布局
    m_titleLayout->addWidget(m_groupLabel);
    m_titleLayout->addStretch();
    m_titleLayout->addWidget(m_iconLabel);
    
    // 为标题栏容器安装事件过滤�?
    titleBar->installEventFilter(this);
    m_groupLabel->installEventFilter(this);
    
    // 将标题栏添加到主布局
    m_mainLayout->addWidget(titleBar);
    
    // 创建内容容器widget
    m_contentWidget = new QWidget(this);
    m_mainLayout->addWidget(m_contentWidget);
    
    setLayout(m_mainLayout);
    
    // 启用鼠标跟踪
    setMouseTracking(true);
}

void SubGroup::setGroupTitle(const QString &title) 
{
    if (m_groupLabel) {
        m_groupLabel->setText(title);
    }
}

void SubGroup::toggleContent() 
{
    m_isExpanded = !m_isExpanded;
    
    // 切换内容区域的可见�?
    if (m_contentWidget) 
    {
        m_contentWidget->setVisible(m_isExpanded);
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

bool SubGroup::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            // 检查是否点击了标题栏相关的组件
            if (obj != m_iconLabel) {
                toggleContent();
                return true;
            }
        }
    }
    return QFrame::eventFilter(obj, event);
}