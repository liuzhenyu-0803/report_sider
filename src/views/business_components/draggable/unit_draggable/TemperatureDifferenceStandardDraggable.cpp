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
    setText(tr("TemperatureDifferenButton"));
}

TemperatureDifferenceStandardDraggable::~TemperatureDifferenceStandardDraggable()
{
}

void TemperatureDifferenceStandardDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent("://html/temperature_difference_standard.html").arg(Model::getInstance()->getThermalImageIndex()).arg("JudgmentCriteria(bName").arg("Normal1Name").arg("NeedToPayAttentioName").arg("LaterMaintenanceName").arg("ImmediateRepair1Name"));
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}