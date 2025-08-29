#include "InstrumentInfoSubGroupFrame.h"
#include "views/business_components/element/unit_element/InstrumentInfoElement.h"
#include <QVBoxLayout>
#include <QMimeData>
#include <QWidget>

InstrumentInfoSubGroupFrame::InstrumentInfoSubGroupFrame(QWidget *parent)
    : FieldSubGroupFrame(parent)
{
    setGroupTitle("Device Info");
    createElements();
}

InstrumentInfoSubGroupFrame::~InstrumentInfoSubGroupFrame()
{
}

void InstrumentInfoSubGroupFrame::createElements()
{
    auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);

    auto dragElement1 = new FieldDraggableElement(this);
    dragElement1->setCustomData("Device Model");
    auto mimeData = new QMimeData();
    mimeData->setText("Device Model");
    dragElement1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement1);

    auto dragElement2 = new FieldDraggableElement(this);
    dragElement2->setCustomData("Device Serial");
    auto mimeData2 = new QMimeData();
    mimeData2->setText("Device Serial");
    dragElement2->setMimeData(mimeData2);
    contentWidgetLayout->addWidget(dragElement2);

    auto dragElement3 = new FieldDraggableElement(this);
    dragElement3->setCustomData("Lens Magnification");
    auto mimeData3 = new QMimeData();
    mimeData3->setText("Lens Magnification");
    dragElement3->setMimeData(mimeData3);
    contentWidgetLayout->addWidget(dragElement3);

    m_elements.append(contentWidget);
}

QList<QWidget*> InstrumentInfoSubGroupFrame::getElements()
{
    return m_elements;
}