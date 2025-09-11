#include "NoteInfoSubGroup.h"
#include "views/business_components/draggable/unit_draggable/TextNoteDraggable.h"
#include "views/common_components/TitleSelector.h"
#include "views/common_components/TitleSpinBox.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"
#include "views/business_components/draggable/unit_draggable/UnitDraggable.h"
#include "models/Model.h"
#include <QJsonObject>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QMimeData>

NoteInfoGroup::NoteInfoGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle(tr("RemarkInformationName"));
}

NoteInfoGroup::~NoteInfoGroup()
{

}

QList<QWidget*> NoteInfoGroup::getElements()
{
    if (m_elements.isEmpty()) {
        auto contentWidget = new QWidget(this);
        auto contentWidgetLayout = new QVBoxLayout(contentWidget);
        contentWidgetLayout->setContentsMargins(0, 0, 0, 0);
        contentWidgetLayout->setSpacing(10);

        dragElement_1 = new FieldDraggable(this);
        setDragElement1Text();
        dragElement_1->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement_1);

        dragElement_2 = new FieldDraggable(this);
        setDragElement2Text();
        dragElement_2->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement_2);

        dragElement_3 = new FieldDraggable(this);
        setDragElement3Text();
        dragElement_3->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement_3);

        m_elements.append(contentWidget);
    }
    return m_elements;
}

bool NoteInfoGroup::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (watched == dragElement_1) {
                setDragElement1MimeData();
            }
            if (watched == dragElement_2) {
                setDragElement2MimeData();
            }
            if (watched == dragElement_3) {
                setDragElement3MimeData();
            }
        }
    }
    return FieldSubGroup::eventFilter(watched, event);
}

void NoteInfoGroup::setDragElement1Text()
{
    dragElement_1->setText(tr("TextNoteButton"));
}

void NoteInfoGroup::setDragElement2Text()
{
    dragElement_2->setText(tr("QRCodeNoteButton"));
}

void NoteInfoGroup::setDragElement3Text()
{
    dragElement_3->setText(tr("FaultRatingButton"));
}

void NoteInfoGroup::setDragElement1MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.tnt}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement_1->setMimeData(mimeData);
}

void NoteInfoGroup::setDragElement2MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.qrc}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement_2->setMimeData(mimeData);
}

void NoteInfoGroup::setDragElement3MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.tnt |Fault}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement_3->setMimeData(mimeData);
}