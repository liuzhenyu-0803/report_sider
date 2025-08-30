#include "TemperatureResultDraggable.h"
#include <QMimeData>
#include <QIcon>

TemperatureResultDraggable::TemperatureResultDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
}

TemperatureResultDraggable::~TemperatureResultDraggable()
{
}

QString TemperatureResultDraggable::getIcon() const
{
    return ":/images/temperature_result.svg";
}

QString TemperatureResultDraggable::getText() const
{
    return "Temperature Result";
}

QMimeData* TemperatureResultDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TemperatureResultDraggable");
    mimeData->setData("application/x-temperatureresult", QByteArray());
    
    return mimeData;
}
