#include "TextNoteDraggable.h"
#include "models/Model.h"
#include <QMimeData>
#include <QIcon>

TextNoteDraggable::TextNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/text_note.svg");
    setText(tr("TextNoteButton"));
}

TextNoteDraggable::~TextNoteDraggable()
{
}

void TextNoteDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/text_note.html").arg(Model::getInstance()->getThermalImageIndex()).arg("TextNoteName"));
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
