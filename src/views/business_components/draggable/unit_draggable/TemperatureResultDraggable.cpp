#include "TemperatureResultDraggable.h"
#include "QcGlobalDefine.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

#include <QDebug>

TemperatureResultDraggable::TemperatureResultDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/temperature_result.svg");
    setText(tr("TemperatureMeasuremButton"));
}

TemperatureResultDraggable::~TemperatureResultDraggable()
{
}

void TemperatureResultDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent("://html/temperature_measurement_results.html").arg(Model::getInstance()->getThermalImageIndex()).arg("TemperatureMeasurem2Name").arg("ImageMaximumTemperaName").arg("ImageMinimumTemperaName").arg("ImageAverageTemperaName").arg("ImageCenterTemperatName").arg("R1MaximumTemperaturName").arg("R1LowestTemperatureName").arg("R1AverageTemperaturName"));
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
