#include "InstrumentInfoSubGroup.h"
#include "views/business_components/draggable/unit_draggable/InstrumentInfoDraggable.h"
#include "models/model.h"
#include <QVBoxLayout>
#include <QMimeData>
#include <QWidget>
#include <QJsonObject>
#include <QEvent>
#include <QMouseEvent>

InstrumentInfoSubGroup::InstrumentInfoSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle(tr("DeviceInformation1Name"));
}

InstrumentInfoSubGroup::~InstrumentInfoSubGroup()
{
}

QList<QWidget*> InstrumentInfoSubGroup::getElements()
{
    if (m_elements.isEmpty()) {
        auto contentWidget = new QWidget(this);
        auto contentWidgetLayout = new QVBoxLayout(contentWidget);
        contentWidgetLayout->setContentsMargins(0, 0, 0, 0);
        contentWidgetLayout->setSpacing(10);

        dragElement1 = new FieldDraggable(this);
        setDragElement1Text();
        dragElement1->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement1);

        dragElement2 = new FieldDraggable(this);
        setDragElement2Text();
        dragElement2->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement2);

        dragElement3 = new FieldDraggable(this);
        setDragElement3Text();
        dragElement3->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement3);

        m_elements.append(contentWidget);
    }
    return m_elements;
}

bool InstrumentInfoSubGroup::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (watched == dragElement1) {
                setDragElement1MimeData();
            } else if (watched == dragElement2) {
                setDragElement2MimeData();
            } else if (watched == dragElement3) {
                setDragElement3MimeData();
            }
        }
    }
    return FieldSubGroup::eventFilter(watched, event);
}

void InstrumentInfoSubGroup::setDragElement1Text()
{
    dragElement1->setText(tr("InstrumentModelButton"));
}

void InstrumentInfoSubGroup::setDragElement2Text()
{
    dragElement2->setText(tr("InstrumentSerialNuButton"));
}

void InstrumentInfoSubGroup::setDragElement3Text()
{
    dragElement3->setText(tr("LensMagnificationButton"));
}

void InstrumentInfoSubGroup::setDragElement1MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("rm%1.dev").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement1->setMimeData(mimeData);
}

void InstrumentInfoSubGroup::setDragElement2MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("rm%1.sno").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement2->setMimeData(mimeData);
}

void InstrumentInfoSubGroup::setDragElement3MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("rm%1.len").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement3->setMimeData(mimeData);
}