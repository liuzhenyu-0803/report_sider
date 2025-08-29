#include "FieldDraggableElement.h"
#include <QMimeData>
#include "FieldDraggableElement.h"

#include <QPainter>

FieldDraggableElement::FieldDraggableElement(QWidget *parent)
    : ElementFrame(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setFixedHeight(32);
    setMouseTracking(true);
}

FieldDraggableElement::~FieldDraggableElement() = default;

void FieldDraggableElement::paintEvent(QPaintEvent *event)
{
    // 绘制一个圆角矩形
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(Qt::lightGray));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect(), 10, 10);
}

QMimeData* FieldDraggableElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    // 设置字段元素的 MIME 数据
    mimeData->setText("FieldDraggableElement");
    mimeData->setData("application/x-fieldelement-frame", QByteArray());
    
    return mimeData;
}
