#include "SummaryTableDraggable.h"
#include "models/model.h"
#include <QIcon>
#include <QMimeData>

SummaryTableDraggable::SummaryTableDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/temperature_result.svg");
    setText(tr("SummarizeTheTableButton"));
}

SummaryTableDraggable::~SummaryTableDraggable()
{
}

void SummaryTableDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/summary_page.html").arg(Model::getInstance()->getThermalImageIndex()));
    setMimeData(mimeData);
}