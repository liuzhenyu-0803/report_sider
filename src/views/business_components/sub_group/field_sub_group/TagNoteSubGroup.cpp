#include "TagNoteSubGroup.h"
#include "views/business_components/title_combine_widget/TemplateTitleSelector.h"
#include <QJsonObject>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QMimeData>

TagNoteSubGroup::TagNoteSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("tag note");
}

TagNoteSubGroup::~TagNoteSubGroup()
{
}

QList<QWidget*> TagNoteSubGroup::getElements()
{
    if (m_elements.isEmpty()) {
        auto contentWidget = new QWidget(this);
        auto contentWidgetLayout = new QVBoxLayout(contentWidget);
        contentWidgetLayout->setContentsMargins(0, 0, 0, 0);
        contentWidgetLayout->setSpacing(10);

        auto templateSelector = new TemplateTitleSelector(this);
        contentWidgetLayout->addWidget(templateSelector);

        dragElement_1 = new FieldDraggable(this);
        dragElement_1->setCustomData(QJsonObject{{"text", "Drag Me"}});
        setDragElementText();
        dragElement_1->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement_1);

        m_elements.append(contentWidget);
    }
    return m_elements;
}

bool TagNoteSubGroup::eventFilter(QObject *watched, QEvent *event)
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

void TagNoteSubGroup::setDragElementText()
{
    dragElement_1->setText("Drag Me");
}

void TagNoteSubGroup::setDragElementMimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText("Drag Me");
    dragElement_1->setMimeData(mimeData);
}