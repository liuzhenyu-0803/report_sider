#include "UnitFrame.h"
#include <QPainter>

UnitFrame::UnitFrame(QWidget *parent)
    : QFrame(parent)
{
    // 设置固定大小或最小大小
    setMinimumSize(200, 150);
}

UnitFrame::~UnitFrame()
{
}

void UnitFrame::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // 绘制绿色背景
    painter.fillRect(rect(), Qt::green);
    
    // 可以在这里添加其他绘制代码
    // 例如，绘制一些文本或其他图形
    painter.setPen(Qt::black);
    painter.drawText(rect(), Qt::AlignCenter, "Unit Frame\n(Green)");
}