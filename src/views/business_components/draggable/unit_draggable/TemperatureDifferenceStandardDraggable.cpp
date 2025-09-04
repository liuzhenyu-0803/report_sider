#include "TemperatureDifferenceStandardDraggable.h"
#include "QcGlobalDefine.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

#include <QDebug>

TemperatureDifferenceStandardDraggable::TemperatureDifferenceStandardDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/temperature_difference_standard.svg");
    setText("Temperature Difference Standard");
}

TemperatureDifferenceStandardDraggable::~TemperatureDifferenceStandardDraggable()
{
}

void TemperatureDifferenceStandardDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent("://html/temperature_difference_standard.html").arg(Model::getInstance()->getThermalImageIndex()));
    setMimeData(mimeData);
}