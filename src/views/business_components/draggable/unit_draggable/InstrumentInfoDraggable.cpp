#include "InstrumentInfoDraggable.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

InstrumentInfoDraggable::InstrumentInfoDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/instrument_info.svg");
    setText("Instrument Info");
}

InstrumentInfoDraggable::~InstrumentInfoDraggable()
{
}

void InstrumentInfoDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/instrument_info.html").arg(Model::getInstance()->getThermalImageIndex()));
    setMimeData(mimeData);
}
