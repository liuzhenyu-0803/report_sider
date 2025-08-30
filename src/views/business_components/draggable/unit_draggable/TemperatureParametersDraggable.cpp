#include "TemperatureParametersDraggable.h"
#include <QMimeData>
#include <QIcon>

TemperatureParametersDraggable::TemperatureParametersDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
}

TemperatureParametersDraggable::~TemperatureParametersDraggable()
{
}

QString TemperatureParametersDraggable::getIcon() const
{
    return ":/images/temperature_parameters.svg";
}

QString TemperatureParametersDraggable::getText() const
{
    return "Temperature Parameters";
}

QMimeData* TemperatureParametersDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TemperatureParametersDraggable");
    mimeData->setData("application/x-temperatureparameters", QByteArray());
    
    return mimeData;
}
