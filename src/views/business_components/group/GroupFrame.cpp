#include "GroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include "views/business_components/element/ElementFrame.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMouseEvent>
#include <QTimer>
#include <QWidget>

GroupFrame::GroupFrame(QWidget *parent)
    : QFrame(parent)
    , m_isExpanded(true)
{
    setupUI();
    
    QTimer::singleShot(0, this, [=]{
        // 调用虚接口函数加载数据
        loadData();
    });
}

GroupFrame::~GroupFrame()
{
}

void GroupFrame::setupUI() {
    // 设置样式
    setStyleSheet("GroupFrame { border: 1px solid #E0E0E0; border-radius: 5px; margin: 5px; }");
    
    // 创建主布局
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(10, 10, 10, 10);
    m_mainLayout->setSpacing(10);
    
    // 创建标题栏容器
    QWidget *titleBar = new QWidget(this);
    titleBar->setStyleSheet("background-color: transparent;");
    
    // 创建标题栏布局
    m_titleLayout = new QHBoxLayout(titleBar);
    m_titleLayout->setContentsMargins(0, 0, 0, 0);
    m_titleLayout->setSpacing(5);
    
    // 创建组标签
    m_groupLabel = new QLabel("Group", this);
    m_groupLabel->setStyleSheet("font-weight: bold; font-size: 14px; margin-top: 5px;");
    
    // 创建切换按钮
    m_toggleButton = new QPushButton(this);
    m_toggleButton->setFixedSize(20, 20);
    m_toggleButton->setStyleSheet("border: none; background-color: transparent;");
    m_toggleButton->setIcon(QIcon(":/images/arrow_up.svg"));
    
    // 连接按钮点击信号到槽函数
    connect(m_toggleButton, &QPushButton::clicked, this, &GroupFrame::toggleContent);
    
    // 将标签和按钮添加到标题栏布局
    m_titleLayout->addWidget(m_groupLabel);
    m_titleLayout->addStretch();
    m_titleLayout->addWidget(m_toggleButton);
    
    // 为标题栏容器安装事件过滤器
    titleBar->installEventFilter(this);
    m_groupLabel->installEventFilter(this);
    
    // 将标题栏添加到主布局
    m_mainLayout->addWidget(titleBar);
    
    setLayout(m_mainLayout);
    
    // 启用鼠标跟踪
    setMouseTracking(true);
}

void GroupFrame::setGroupTitle(const QString &title) {
    if (m_groupLabel) {
        m_groupLabel->setText(title);
    }
}

void GroupFrame::toggleContent() {
    m_isExpanded = !m_isExpanded;
    
    // 切换内容区域的可见性
    // 注意：这里不再直接操作m_contentLayout，而是由子类负责管理自己的内容布局
    QWidget *contentWidget = nullptr;
    if (m_mainLayout && m_mainLayout->count() > 1) {
        QLayoutItem *item = m_mainLayout->itemAt(1);
        if (item && item->widget()) {
            contentWidget = item->widget();
        }
    }
    
    if (contentWidget) {
        contentWidget->setVisible(m_isExpanded);
    }
    
    // 更新按钮图标
    if (m_isExpanded) {
        m_toggleButton->setIcon(QIcon(":/images/arrow_up.svg"));
    } else {
        m_toggleButton->setIcon(QIcon(":/images/arrow_down.svg"));
    }
}

bool GroupFrame::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            // 检查是否点击了标题栏相关的组件
            if (obj != m_toggleButton) {
                toggleContent();
                return true;
            }
        }
    }
    return QFrame::eventFilter(obj, event);
}