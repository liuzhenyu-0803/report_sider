#include "GeographicInfoSubGroupFrame.h"
#include "views/business_components/element/unit_element/ImageInfoElement.h"

GeographicInfoSubGroupFrame::GeographicInfoSubGroupFrame(QWidget *parent)
    : FieldSubGroupFrame(parent)
{
    setGroupTitle("地理信息");
    createElements();
}

GeographicInfoSubGroupFrame::~GeographicInfoSubGroupFrame()
{
}

void GeographicInfoSubGroupFrame::createElements()
{
    auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);

    auto dragElement1 = new FieldDraggableElement(this);
    dragElement1->setCustomData("GPS");
    auto mimeData = new QMimeData();
    mimeData->setText("GPS");
    dragElement1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement1);

    auto dragElement2 = new FieldDraggableElement(this);
    dragElement2->setCustomData("电子罗盘");
    auto mimeData2 = new QMimeData();
    mimeData2->setText("电子罗盘");
    dragElement2->setMimeData(mimeData2);
    contentWidgetLayout->addWidget(dragElement2);
    
    m_elements.append(contentWidget);
}

QList<QWidget*> GeographicInfoSubGroupFrame::getElements()
{
    return m_elements;
}