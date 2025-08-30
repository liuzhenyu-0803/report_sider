#include "TextNoteDraggable.h"
#include <QMimeData>
#include <QIcon>

TextNoteDraggable::TextNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
}

TextNoteDraggable::~TextNoteDraggable()
{
}

QString TextNoteDraggable::getIcon() const
{
    return ":/images/text_note.svg";
}

QString TextNoteDraggable::getText() const
{
    return "Text Note";
}

QMimeData* TextNoteDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TextNoteDraggable");
    mimeData->setData("application/x-textnote", QByteArray());
    
    return mimeData;
}
