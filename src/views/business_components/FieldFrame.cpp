#include "FieldFrame.h"
#include <QPainter>

FieldFrame::FieldFrame(QWidget *parent)
    : QFrame(parent)
{
    // 设置固定大小或最小大小
    setMinimumSize(200, 150);
}

FieldFrame::~FieldFrame()
{
}

void FieldFrame::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // 绘制红色背景
    painter.fillRect(rect(), Qt::red);
    
    // 可以在这里添加其他绘制代码
    // 例如，绘制一些文本或其他图形
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, "Field Frame\n(Red)");
}