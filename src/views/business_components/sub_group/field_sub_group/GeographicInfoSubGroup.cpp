#include "GeographicInfoSubGroup.h"
#include "views/business_components/draggable/unit_draggable/ImageInfoDraggable.h"

GeographicInfoSubGroup::GeographicInfoSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("地理信息");
    createElements();
}

GeographicInfoSubGroup::~GeographicInfoSubGroup()
{
}

void GeographicInfoSubGroup::createElements()
{
    auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);

    auto dragElement1 = new FieldDraggable(this);
    dragElement1->setCustomData("GPS");
    auto mimeData = new QMimeData();
    mimeData->setText("GPS");
    dragElement1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement1);

    auto dragElement2 = new FieldDraggable(this);
    dragElement2->setCustomData("电子罗盘");
    auto mimeData2 = new QMimeData();
    mimeData2->setText("电子罗盘");
    dragElement2->setMimeData(mimeData2);
    contentWidgetLayout->addWidget(dragElement2);
    
    m_elements.append(contentWidget);
}

QList<QWidget*> GeographicInfoSubGroup::getElements()
{
    return m_elements;
}