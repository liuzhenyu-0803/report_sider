#include "FieldDraggable.h"
#include <QMimeData>
#include <QPainter>

FieldDraggable::FieldDraggable(QWidget *parent)
    : Draggable(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setFixedHeight(32);
    setMouseTracking(true);
}

FieldDraggable::~FieldDraggable() = default;

void FieldDraggable::paintEvent(QPaintEvent *event)
{
    // 绘制一个圆角矩形
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QColor("#BBD0FF")));
    // brush设置为渐变色 从左到右的颜色分别是#3976FF透明度0到#3976FF透明度0.6
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
}

QMimeData* FieldDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    // 设置字段元素的 MIME 数据
    mimeData->setText("FieldDraggable");
    mimeData->setData("application/x-fieldelement-frame", QByteArray());
    
    return mimeData;
}