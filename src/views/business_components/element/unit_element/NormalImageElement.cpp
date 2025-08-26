#include "NormalImageElement.h"
#include <QMimeData>
#include <QIcon>

NormalImageElement::NormalImageElement(QWidget *parent)
    : UnitElementFrame(parent)
{
    
}

NormalImageElement::~NormalImageElement()
{
}

QString NormalImageElement::getIcon() const
{
    return ":/images/normal_image.svg";
}

QString NormalImageElement::getText() const
{
    return "Normal Image";
}

QMimeData* NormalImageElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("NormalImageElement");
    mimeData->setData("application/x-normalimage", QByteArray());
    
    return mimeData;
}