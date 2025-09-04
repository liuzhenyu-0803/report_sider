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

void FieldDraggable::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QColor("#BBD0FF")));
    QLinearGradient gradient(0, 0, width(), 0);
    QColor color("#3976FF");
    QColor colorStart = color;
    colorStart.setAlphaF(0);
    QColor colorEnd = color;
    colorEnd.setAlphaF(0.3);
    gradient.setColorAt(0, colorStart);
    gradient.setColorAt(1, colorEnd);
    painter.setBrush(gradient);
    painter.drawRoundedRect(rect(), 4, 4);

    painter.setPen(QPen(GET_COLOR("text/text_primary")));
    painter.drawText(rect().adjusted(4, 0, -4, 0), Qt::AlignCenter, getCustomData()["text"].toString());
}