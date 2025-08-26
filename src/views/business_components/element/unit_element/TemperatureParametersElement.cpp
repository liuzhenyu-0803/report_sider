#include "TemperatureParametersElement.h"
#include <QMimeData>
#include <QIcon>

TemperatureParametersElement::TemperatureParametersElement(QWidget *parent)
    : UnitElementFrame(parent)
{
}

TemperatureParametersElement::~TemperatureParametersElement()
{
}

QString TemperatureParametersElement::getIcon() const
{
    return ":/images/temperature_parameters.svg";
}

QString TemperatureParametersElement::getText() const
{
    return "Temperature Parameters";
}

QMimeData* TemperatureParametersElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TemperatureParametersElement");
    mimeData->setData("application/x-temperatureparameters", QByteArray());
    
    return mimeData;
}