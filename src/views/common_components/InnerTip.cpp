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
    // 设置对象名称，便于在qss中设置样式
    setObjectName("innerTipFrame");
    
    // 创建主布局，直接在InnerTip上布局
    m_mainLayout = new QHBoxLayout(this);
    m_mainLayout->setContentsMargins(8, 6, 8, 6);
    m_mainLayout->setSpacing(4);  // 设置图标和文本之间的间距
    
    // 创建icon标签
    m_iconLabel = new QLabel(this);
    m_iconLabel->setObjectName("innerTipIcon"); // 设置对象名称，便于在qss中设置样式
    m_iconLabel->setFixedSize(16, 16);
    
    // 创建文本浏览器
    m_textBrowser = new QTextBrowser(this);
    m_textBrowser->setObjectName("innerTipText"); // 设置对象名称，便于在qss中设置样式
    m_textBrowser->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_textBrowser->setFrameStyle(QFrame::NoFrame);
    m_textBrowser->document()->setDocumentMargin(2);
    connect(m_textBrowser->document()->documentLayout(), &QAbstractTextDocumentLayout::documentSizeChanged, [this](const QSizeF &newSize){
        m_textBrowser->setFixedHeight(newSize.height());
    });
    
    // 添加到布局
    m_mainLayout->addWidget(m_iconLabel);
    m_mainLayout->addWidget(m_textBrowser);
    m_mainLayout->setAlignment(m_iconLabel, Qt::AlignTop);
    
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

    style()->polish(this);

    // 重新应用样式表
    // setStyleSheet(getFileContent(":/qss/InnerTip.qss"));
    
    // 触发重绘
    update();
}

void InnerTip::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    // 在这里添加自定义绘制代码
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);

    // 绘制背景
    if (m_styleType == Brand) {
        painter.setBrush(QColor("#DDEEFF"));
    } else {
        painter.setBrush(QColor("#F3F3F4"));
    }
    painter.drawRoundRect(contentsRect(), 5, 5);
}