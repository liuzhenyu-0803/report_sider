#include "ImageNoteElement.h"
#include <QMimeData>
#include <QIcon>

ImageNoteElement::ImageNoteElement(QWidget *parent)
    : UnitElementFrame(parent)
{
}

ImageNoteElement::~ImageNoteElement()
{
}

QString ImageNoteElement::getIcon() const
{
    return ":/images/image_note.svg";
}

QString ImageNoteElement::getText() const
{
    return "Image Note";
}

QMimeData* ImageNoteElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("ImageNoteElement");
    mimeData->setData("application/x-imagenote", QByteArray());
    
    return mimeData;
}