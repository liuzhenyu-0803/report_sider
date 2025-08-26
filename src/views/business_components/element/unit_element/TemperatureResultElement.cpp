#include "TemperatureResultElement.h"
#include <QMimeData>
#include <QIcon>

TemperatureResultElement::TemperatureResultElement(QWidget *parent)
    : UnitElementFrame(parent)
{
}

TemperatureResultElement::~TemperatureResultElement()
{
}

QString TemperatureResultElement::getIcon() const
{
    return ":/images/temperature_result.svg";
}

QString TemperatureResultElement::getText() const
{
    return "Temperature Result";
}

QMimeData* TemperatureResultElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TemperatureResultElement");
    mimeData->setData("application/x-temperatureresult", QByteArray());
    
    return mimeData;
}