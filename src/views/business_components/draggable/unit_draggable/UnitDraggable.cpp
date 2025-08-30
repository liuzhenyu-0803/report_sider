#include "UnitDraggable.h"
#include "QcLabel.h"
#include "QcMultiLineText.h"
#include "QcStyleManager.h"
#include <QVBoxLayout>
#include <QPainter>

UnitDraggable::UnitDraggable(QWidget *parent)
    : Draggable(parent) {
    setFixedSize(104, 64);
    setMouseTracking(true);
    setupUI();
}

UnitDraggable::~UnitDraggable() = default;

void UnitDraggable::loadData()
{
    m_iconLabel->SetIconPath(getIcon());
    m_iconLabel->SetIconColorParams("#000000, 0.9");
    m_multiLineText->setText(getText());
}

void UnitDraggable::onIconButtonClicked()
{
    if (m_moreMenu) {
        m_moreMenu->setVisible(!m_moreMenu->isVisible());
        if (m_moreMenu->isVisible()) {
            // menu左上角与UnitDraggable右上角对齐
            m_moreMenu->move(mapToGlobal(QPoint(width(), 0)));
        }
    }
}

void UnitDraggable::setIconButtonVisible(bool visible)
{
    if (m_iconButton) {
        m_iconButton->setVisible(visible);
    }
}

QLayout *UnitDraggable::getMoreMenuContentLayout() const
{
    return m_moreMenu->getContentLayout();
}

void UnitDraggable::setupUI()
{
    // 创建垂直布局
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(6, 6, 6, 6);
    m_layout->setSpacing(0);

    // 创建图标标签
    m_iconLabel = new MicroUI::QcLabel(this);
    m_iconLabel->setFixedSize(24, 24);
    m_iconLabel->setAlignment(Qt::AlignCenter);
    m_layout->addWidget(m_iconLabel, 0, Qt::AlignCenter);

    // 创建标题标签
    m_multiLineText = new MicroUI::QcMultiLineText(this);
    m_multiLineText->setAlignment(Qt::AlignCenter);
    m_multiLineText->setHeightAdaptive(true);
    QFont font;
    font.setPixelSize(12);
    m_multiLineText->setFont(font);
    m_multiLineText->setLineCount(2);
    m_layout->addWidget(m_multiLineText);

    m_iconButton = new MicroUI::QcIconButton(this);
    m_iconButton->setFixedSize(14, 14);
    m_iconButton->SetIconPath(":/images/more.svg");
    m_iconButton->move(width() - m_iconButton->width() - 5, 5);

    m_moreMenu = new MoreMenu(this);
    m_moreMenu->setVisible(false);
    
    // 设置布局
    setLayout(m_layout);

    connect(m_iconButton, &MicroUI::QcIconButton::clicked, this, &UnitDraggable::onIconButtonClicked);

    setIconButtonVisible(false);
}

void UnitDraggable::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 判断悬浮状态
    bool hovered = underMouse();

    // 设置边框和背景色
    QColor borderColor = hovered ? QColor("#336FFF") : QColor("#AAC4FF");
    QColor bgColor = hovered ? QColor("#F1F5FF") : QColor("#FFFFFF");

    // 绘制边框
    QPen pen(borderColor, 1);
    painter.setPen(pen);
    painter.setBrush(bgColor);
    painter.drawRoundRect(rect(), 10, 10);
}