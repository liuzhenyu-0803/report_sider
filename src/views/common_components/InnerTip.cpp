#include "InnerTip.h"

#include "utility/utility.h"

#include <QLabel>
#include <QTextBrowser>
#include <QHBoxLayout>
#include <QPixmap>
#include <QSizePolicy>
#include <QAbstractTextDocumentLayout>
#include <QStyle>

InnerTip::InnerTip(QWidget *parent)
    : QFrame(parent)
    , m_styleType(Brand)  // 默认为品牌样式
    , m_showIcon(true)    // 默认显示图标
{
    setupUI();
}

InnerTip::~InnerTip()
{
}

void InnerTip::setupUI()
{
    // 创建主布局
    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(0);  // 主布局不设置间距
    
    // 创建内部容器框架
    m_innerFrame = new QFrame(this);
    m_innerFrame->setObjectName("innerTipFrame"); // 设置对象名称，便于在qss中设置样式
    
    // 创建icon标签
    m_iconLabel = new QLabel(m_innerFrame);  // 父对象改为内部容器
    m_iconLabel->setObjectName("innerTipIcon"); // 设置对象名称，便于在qss中设置样式
    m_iconLabel->setFixedSize(16, 16);
    
    // 创建文本浏览器
    m_textBrowser = new QTextBrowser(m_innerFrame);  // 父对象改为内部容器
    m_textBrowser->setObjectName("innerTipText"); // 设置对象名称，便于在qss中设置样式
    m_textBrowser->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_textBrowser->setFrameStyle(QFrame::NoFrame);
    m_textBrowser->document()->setDocumentMargin(2);
    connect(m_textBrowser->document()->documentLayout(), &QAbstractTextDocumentLayout::documentSizeChanged, [this](const QSizeF &newSize){
        m_textBrowser->setFixedHeight(newSize.height());
    });
    
    // 创建内部容器的布局
    QHBoxLayout *innerLayout = new QHBoxLayout(m_innerFrame);
    innerLayout->setContentsMargins(8, 6, 8, 6);
    innerLayout->setSpacing(4);  // 内部布局设置图标和文本之间的间距
    
    // 添加到内部布局
    innerLayout->addWidget(m_iconLabel);
    innerLayout->addWidget(m_textBrowser);
    innerLayout->setAlignment(m_iconLabel, Qt::AlignTop);
    
    m_innerFrame->setLayout(innerLayout);
    
    // 将内部容器添加到主布局
    m_mainLayout->addWidget(m_innerFrame);
    
    setLayout(m_mainLayout);

    setStyleSheet(getFileContent(":/qss/InnerTip.qss"));
}

void InnerTip::setText(const QString &text)
{
    if (m_textBrowser) {
        m_textBrowser->setText(text);
    }
}

void InnerTip::setStyleType(StyleType styleType)
{
    if (m_styleType != styleType) {
        m_styleType = styleType;
        updateStyle();
    }
}

void InnerTip::setShowIcon(bool show)
{
    if (m_showIcon != show) {
        m_showIcon = show;
        m_iconLabel->setVisible(m_showIcon);
    }
}

void InnerTip::updateStyle()
{
    // 设置属性以便在样式表中使用
    setProperty("styleType", m_styleType == Brand ? "Brand" : "Gray");
    
    // 重新应用样式表
    setStyleSheet(getFileContent(":/qss/InnerTip.qss"));
    
    // 触发重绘
    update();
}