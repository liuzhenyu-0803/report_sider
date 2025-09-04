#include "TemperatureParametersDraggable.h"
#include "QcGlobalDefine.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

#include <QDebug>

TemperatureParametersDraggable::TemperatureParametersDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/temperature_parameters.svg");
    setText("Temperature Parameters");  
}

TemperatureParametersDraggable::~TemperatureParametersDraggable()
{
}

void TemperatureParametersDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/temperature_measurement_parameters.html").arg(Model::getInstance()->getThermalImageIndex()));
    setMimeData(mimeData);
}
