#include "InstrumentInfoDraggable.h"
#include <QMimeData>
#include <QIcon>

InstrumentInfoDraggable::InstrumentInfoDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
}

InstrumentInfoDraggable::~InstrumentInfoDraggable()
{
}

QString InstrumentInfoDraggable::getIcon() const
{
    return ":/images/instrument_info.svg";
}

QString InstrumentInfoDraggable::getText() const
{
    return "Instrument Info";
}

QMimeData* InstrumentInfoDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("InstrumentInfoDraggable");
    mimeData->setData("application/x-instrumentinfo", QByteArray());
    
    return mimeData;
}
