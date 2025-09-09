#include "FieldDraggable.h"
#include "QcStyleManager.h"
#include <QMimeData>
#include <QPainter>
#include <QLabel>
#include <QJsonObject>

FieldDraggable::FieldDraggable(QWidget *parent)
    : Draggable(parent)
{
    setFixedHeight(32);

    m_iconButton = new MicroUI::QcIconButton(this);
    m_iconButton->setFixedSize(20, 20);
    m_iconButton->SetIconPath(":/images/more.svg");
    m_iconButton->setVisible(false);

    m_moreMenu = new MoreMenu();
    m_moreMenu->setVisible(false);
    
    connect(m_iconButton, &MicroUI::QcIconButton::clicked, this, &FieldDraggable::onIconButtonClicked);

    setIconButtonVisible(false);
}

FieldDraggable::~FieldDraggable() = default;

void FieldDraggable::setText(const QString& text)
{
    // FieldDraggable通常用于显示文本字段，这里可以添加文本显示逻辑
    // 更新自定义数据中的文本内容
    QJsonObject customData = getCustomData();
    customData["text"] = text;
    setCustomData(customData);
}

void FieldDraggable::setIconButtonVisible(bool visible)
{
    if (m_iconButton) 
    {
        m_iconButton->setVisible(visible);
    }
}

QWidget *FieldDraggable::getMoreMenu() const
{
    return m_moreMenu;
}

void FieldDraggable::setMoreMenuTitle(const QString &title)
{
    if (m_moreMenu) 
    {
        m_moreMenu->setTitle(title);
    }
}

QLayout *FieldDraggable::getMoreMenuContentLayout() const
{
    return m_moreMenu->getContentLayout();
}

void FieldDraggable::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QColor("#BBD0FF")));
    QLinearGradient gradient(0, 0, width(), 0);
    QColor color("#F2F7FF");
    QColor colorStart = color;
    colorStart.setAlphaF(0);
    QColor colorEnd = color;
    colorEnd.setAlphaF(1);
    gradient.setColorAt(0, colorStart);
    gradient.setColorAt(1, colorEnd);
    painter.setBrush(gradient);
    painter.drawRoundedRect(rect(), 4, 4);

    painter.setPen(QPen(GET_COLOR("text/text_primary")));
    painter.drawText(rect().adjusted(4, 0, -4, 0), Qt::AlignCenter, getCustomData()["text"].toString());
}

void FieldDraggable::resizeEvent(QResizeEvent *event)
{
    m_iconButton->move(width() - m_iconButton->width() - 6, 6);

    Draggable::resizeEvent(event);
}

void FieldDraggable::onIconButtonClicked()
{
        if (m_moreMenu) 
    {
        m_moreMenu->setVisible(!m_moreMenu->isVisible());
        if (m_moreMenu->isVisible()) 
        {
            // menu左上角与UnitDraggable右上角对齐
            m_moreMenu->move(mapToGlobal(QPoint(width() - m_moreMenu->width(), height() + 4)));
        }
    }
}