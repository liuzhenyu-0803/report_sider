#include "GroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include "views/business_components/element/ElementFrame.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMouseEvent>
#include <QWidget>

GroupFrame::GroupFrame(QWidget *parent)
    : QFrame(parent)
    , m_isExpanded(true)
{
    setupUI();
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
    
    // 创建内容布局
    m_contentLayout = new QVBoxLayout();
    m_contentLayout->setAlignment(Qt::AlignTop);
    
    // 将标题栏和内容布局添加到主布局
    m_mainLayout->addWidget(titleBar);
    m_mainLayout->addLayout(m_contentLayout);
    
    setLayout(m_mainLayout);
    
    // 启用鼠标跟踪
    setMouseTracking(true);
}

void GroupFrame::createElementFrames() {
    // 此处已移除模型相关逻辑
}

void GroupFrame::setGroupTitle(const QString &title) {
    if (m_groupLabel) {
        m_groupLabel->setText(title);
    }
}

void GroupFrame::setElementFrameList(const QList<ElementFrame *> &elementFrames) {
    // 清空现有的元素框架
    if (m_contentLayout) {
        QLayoutItem *item;
        while ((item = m_contentLayout->takeAt(0))) {
            delete item->widget();
            delete item;
        }
    }

    // 添加新的元素框架
    for (ElementFrame *frame : elementFrames) {
        if (m_contentLayout) {
            m_contentLayout->addWidget(frame);
        }
    }
}

void GroupFrame::toggleContent() {
    m_isExpanded = !m_isExpanded;
    
    // 切换内容区域的可见性
    for (int i = 0; i < m_contentLayout->count(); ++i) {
        QLayoutItem *item = m_contentLayout->itemAt(i);
        if (item->widget()) {
            item->widget()->setVisible(m_isExpanded);
        }
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