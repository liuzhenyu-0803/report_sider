#include "ImageNoteDraggable.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

ImageNoteDraggable::ImageNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/image_note.svg");
    setText(tr("ImageCaptionButton"));
}

ImageNoteDraggable::~ImageNoteDraggable()
{
}

void ImageNoteDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/image_note.html").arg(Model::getInstance()->getThermalImageIndex()));
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
