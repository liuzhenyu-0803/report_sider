#include "GeographicInfoSubGroup.h"
#include "views/business_components/draggable/unit_draggable/ImageInfoDraggable.h"
#include "models/model.h"
#include <QJsonObject>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QMimeData>

GeographicInfoSubGroup::GeographicInfoSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle(tr("geometry info"));
}

GeographicInfoSubGroup::~GeographicInfoSubGroup()
{
}

QList<QWidget*> GeographicInfoSubGroup::getElements()
{
    if (m_elements.isEmpty()) {
        auto contentWidget = new QWidget(this);
        auto contentWidgetLayout = new QVBoxLayout(contentWidget);
        contentWidgetLayout->setContentsMargins(0, 0, 0, 0);
        contentWidgetLayout->setSpacing(10);

        dragElement1 = new FieldDraggable(this);
        setDraggable1Text();
        dragElement1->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement1);

        dragElement2 = new FieldDraggable(this);
        setDraggable2Text();
        dragElement2->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement2);
        
        m_elements.append(contentWidget);
    }
    return m_elements;
}

bool GeographicInfoSubGroup::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (watched == dragElement1) {
                setDraggable1MimeData();
            } else if (watched == dragElement2) {
                setDraggable2MimeData();
            }
        }
    }
    return FieldSubGroup::eventFilter(watched, event);
}

void GeographicInfoSubGroup::setDraggable1Text()
{
    dragElement1->setText(tr("GPS"));
}

void GeographicInfoSubGroup::setDraggable2Text()
{
    dragElement2->setText(tr("electronic compass"));
}

void GeographicInfoSubGroup::setDraggable1MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.GPS}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement1->setMimeData(mimeData);
}

void GeographicInfoSubGroup::setDraggable2MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.cps}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement2->setMimeData(mimeData);
}