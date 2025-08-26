#include "QrCodeNoteElement.h"
#include <QMimeData>
#include <QIcon>

QrCodeNoteElement::QrCodeNoteElement(QWidget *parent)
    : UnitElementFrame(parent)
{
}

QrCodeNoteElement::~QrCodeNoteElement()
{
}

QString QrCodeNoteElement::getIcon() const
{
    return ":/images/qr_code_note.svg";
}

QString QrCodeNoteElement::getText() const
{
    return "QR Code Note";
}

QMimeData* QrCodeNoteElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("QrCodeNoteElement");
    mimeData->setData("application/x-qrcodenote", QByteArray());
    
    return mimeData;
}