#include "QrCodeNoteDraggable.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

QrCodeNoteDraggable::QrCodeNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/qr_code_note.svg");
    setText(tr("QRCodeNoteButton"));
}

QrCodeNoteDraggable::~QrCodeNoteDraggable()
{

}

void QrCodeNoteDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/qr_code_note.html").arg(Model::getInstance()->getThermalImageIndex()).arg("QRCodeNoteName"));
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
