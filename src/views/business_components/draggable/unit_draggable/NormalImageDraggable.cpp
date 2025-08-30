#include "NormalImageDraggable.h"
#include <QMimeData>
#include <QIcon>

NormalImageDraggable::NormalImageDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    
}

NormalImageDraggable::~NormalImageDraggable()
{
}

QString NormalImageDraggable::getIcon() const
{
    return ":/images/normal_image.svg";
}

QString NormalImageDraggable::getText() const
{
    return "Normal Image";
}

QMimeData* NormalImageDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("NormalImageDraggable");
    mimeData->setData("application/x-normalimage", QByteArray());
    
    return mimeData;
}
