#include "FieldElementFrame.h"
#include <QMimeData>

FieldElementFrame::FieldElementFrame(QWidget *parent)
    : ElementFrame(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setFixedSize(100, 100);
    setMouseTracking(true);
}

FieldElementFrame::~FieldElementFrame() = default;

void FieldElementFrame::loadData()
{
    
}

QMimeData* FieldElementFrame::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    // 设置字段元素的 MIME 数据
    mimeData->setText("FieldElementFrame");
    mimeData->setData("application/x-fieldelement-frame", QByteArray());
    
    return mimeData;
}