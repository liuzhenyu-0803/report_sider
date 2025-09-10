#include "InstrumentInfoDraggable.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

InstrumentInfoDraggable::InstrumentInfoDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/instrument_info.svg");
    setText(tr("InstrumentInformatiButton"));
}

InstrumentInfoDraggable::~InstrumentInfoDraggable()
{
}

void InstrumentInfoDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/instrument_info.html").arg(Model::getInstance()->getThermalImageIndex()).arg(tr("InstrumentInformatiName")).arg(tr("InstrumentModelName")).arg(tr("InstrumentSerialNuName")).arg(tr("LensMagnificationName")));
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
