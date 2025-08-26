#include "ImageInfoElement.h"
#include <QMimeData>
#include <QIcon>

ImageInfoElement::ImageInfoElement(QWidget *parent)
    : UnitElementFrame(parent)
{
}

ImageInfoElement::~ImageInfoElement()
{
}

QString ImageInfoElement::getIcon() const
{
    return ":/images/image_info.svg";
}

QString ImageInfoElement::getText() const
{
    return "Image Info";
}

QMimeData* ImageInfoElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("ImageInfoElement");
    mimeData->setData("application/x-imageinfo", QByteArray());
    
    return mimeData;
}