#include "QrCodeNoteDraggable.h"
#include <QMimeData>
#include <QIcon>

QrCodeNoteDraggable::QrCodeNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
}

QrCodeNoteDraggable::~QrCodeNoteDraggable()
{
}

QString QrCodeNoteDraggable::getIcon() const
{
    return ":/images/qr_code_note.svg";
}

QString QrCodeNoteDraggable::getText() const
{
    return "QR Code Note";
}

QMimeData* QrCodeNoteDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("QrCodeNoteDraggable");
    mimeData->setData("application/x-qrcodenote", QByteArray());
    
    return mimeData;
}
