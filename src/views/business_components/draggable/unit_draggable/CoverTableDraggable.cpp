#include "CoverTableDraggable.h"
#include "models/model.h"
#include <QIcon>
#include <QMimeData>

CoverTableDraggable::CoverTableDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/temperature_parameters.svg");
    setText("Cover Table");
}

CoverTableDraggable::~CoverTableDraggable()
{
}

void CoverTableDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/cover_page.html").arg(Model::getInstance()->getThermalImageIndex()));
    setMimeData(mimeData);
}