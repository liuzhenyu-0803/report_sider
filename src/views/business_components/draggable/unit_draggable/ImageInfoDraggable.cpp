#include "ImageInfoDraggable.h"
#include <QMimeData>
#include <QIcon>

ImageInfoDraggable::ImageInfoDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
}

ImageInfoDraggable::~ImageInfoDraggable()
{
}

QString ImageInfoDraggable::getIcon() const
{
    return ":/images/image_info.svg";
}

QString ImageInfoDraggable::getText() const
{
    return "Image Info";
}

QMimeData* ImageInfoDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("ImageInfoDraggable");
    mimeData->setData("application/x-imageinfo", QByteArray());
    
    return mimeData;
}
