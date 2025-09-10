#include "CoverTableDraggable.h"
#include "models/model.h"
#include <QIcon>
#include <QMimeData>

CoverTableDraggable::CoverTableDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/temperature_parameters.svg");
    setText(tr("CoverSheetButton"));
}

CoverTableDraggable::~CoverTableDraggable()
{
}


void CoverTableDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/cover_page.html").arg(tr("CoverFormName")).arg(tr("CustomerName")).arg(tr("AddressName")).arg(tr("DateName")).arg(tr("InspectorName")));
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}