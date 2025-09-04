#include "TextNoteSubGroup.h"
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

TextNoteSubGroup::TextNoteSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("Text Note");
}

TextNoteSubGroup::~TextNoteSubGroup()
{

}

QList<QWidget*> TextNoteSubGroup::getElements()
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

bool TextNoteSubGroup::eventFilter(QObject *watched, QEvent *event)
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

void TextNoteSubGroup::setDragElementText()
{
    dragElement_1->setText(tr("text note"));
}

void TextNoteSubGroup::setDragElementMimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("rm%1.tnt").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement_1->setMimeData(mimeData);
}