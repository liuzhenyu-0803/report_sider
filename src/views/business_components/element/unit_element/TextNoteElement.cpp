#include "TextNoteElement.h"
#include <QMimeData>
#include <QIcon>

TextNoteElement::TextNoteElement(QWidget *parent)
    : UnitElementFrame(parent)
{
}

TextNoteElement::~TextNoteElement()
{
}

QString TextNoteElement::getIcon() const
{
    return ":/images/text_note.svg";
}

QString TextNoteElement::getText() const
{
    return "Text Note";
}

QMimeData* TextNoteElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TextNoteElement");
    mimeData->setData("application/x-textnote", QByteArray());
    
    return mimeData;
}