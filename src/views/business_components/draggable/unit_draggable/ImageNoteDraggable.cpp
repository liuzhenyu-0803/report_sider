#include "ImageNoteDraggable.h"
#include <QMimeData>
#include <QIcon>

ImageNoteDraggable::ImageNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
}

ImageNoteDraggable::~ImageNoteDraggable()
{
}

QString ImageNoteDraggable::getIcon() const
{
    return ":/images/image_note.svg";
}

QString ImageNoteDraggable::getText() const
{
    return "Image Note";
}

QMimeData* ImageNoteDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("ImageNoteDraggable");
    mimeData->setData("application/x-imagenote", QByteArray());
    
    return mimeData;
}
