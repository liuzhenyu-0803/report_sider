#include "QrCodeNoteSubGroup.h"
#include "views/business_components/draggable/unit_draggable/QrCodeNoteDraggable.h"
#include "views/business_components/title_combine_widget/TemplateTitleSelector.h"
#include "models/Model.h"
#include <QJsonObject>
#include <QVBoxLayout>
#include <QMimeData>
#include <QEvent>
#include <QMouseEvent>

QrCodeNoteSubGroup::QrCodeNoteSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("QR Code Note");
}

QrCodeNoteSubGroup::~QrCodeNoteSubGroup()
{

}

QList<QWidget*> QrCodeNoteSubGroup::getElements()
{
    if (m_elements.isEmpty()) {
        auto contentWidget = new QWidget(this);
        auto contentWidgetLayout = new QVBoxLayout(contentWidget);
        contentWidgetLayout->setContentsMargins(0, 0, 0, 0);
        contentWidgetLayout->setSpacing(10);

        dragElement_1 = new FieldDraggable(this);
        dragElement_1->setCustomData(QJsonObject{{"text", "Drag Me"}});
        setDragElementText();
        dragElement_1->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement_1);

        m_elements.append(contentWidget);
    }
    return m_elements;
}

bool QrCodeNoteSubGroup::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (watched == dragElement_1) {
                setDragElementMimeData();
            }
        }
    }
    return FieldSubGroup::eventFilter(watched, event);
}

void QrCodeNoteSubGroup::setDragElementText()
{
    dragElement_1->setText(tr("qr code note"));
}

void QrCodeNoteSubGroup::setDragElementMimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("rm%1.qrc").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement_1->setMimeData(mimeData);
}