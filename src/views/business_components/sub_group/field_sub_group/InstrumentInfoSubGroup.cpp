#include "InstrumentInfoSubGroup.h"
#include "views/business_components/draggable/unit_draggable/InstrumentInfoDraggable.h"
#include <QVBoxLayout>
#include <QMimeData>
#include <QWidget>

InstrumentInfoSubGroup::InstrumentInfoSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("Device Info");
    createElements();
}

InstrumentInfoSubGroup::~InstrumentInfoSubGroup()
{
}

void InstrumentInfoSubGroup::createElements()
{
    auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);

    auto dragElement1 = new FieldDraggable(this);
    dragElement1->setCustomData("Device Model");
    auto mimeData = new QMimeData();
    mimeData->setText("Device Model");
    dragElement1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement1);

    auto dragElement2 = new FieldDraggable(this);
    dragElement2->setCustomData("Device Serial");
    auto mimeData2 = new QMimeData();
    mimeData2->setText("Device Serial");
    dragElement2->setMimeData(mimeData2);
    contentWidgetLayout->addWidget(dragElement2);

    auto dragElement3 = new FieldDraggable(this);
    dragElement3->setCustomData("Lens Magnification");
    auto mimeData3 = new QMimeData();
    mimeData3->setText("Lens Magnification");
    dragElement3->setMimeData(mimeData3);
    contentWidgetLayout->addWidget(dragElement3);

    m_elements.append(contentWidget);
}

QList<QWidget*> InstrumentInfoSubGroup::getElements()
{
    return m_elements;
}