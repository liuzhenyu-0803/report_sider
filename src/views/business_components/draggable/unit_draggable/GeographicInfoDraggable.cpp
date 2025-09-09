#include "GeographicInfoDraggable.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

GeographicInfoDraggable::GeographicInfoDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/geographic_info.svg");
    setText(tr("GeographicInformatiButton"));  
}

GeographicInfoDraggable::~GeographicInfoDraggable()
{
    
}

void GeographicInfoDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/geographic_info.html").arg(Model::getInstance()->getThermalImageIndex()));
    setMimeData(mimeData);
}