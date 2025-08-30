#include "TextNoteSubGroup.h"
#include "views/business_components/draggable/unit_draggable/TextNoteDraggable.h"
#include "views/common_components/TitleSelector.h"
#include "views/common_components/TitleSpinBox.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"
#include "views/business_components/draggable/unit_draggable/UnitDraggable.h"

TextNoteSubGroup::TextNoteSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("Text Note");
    createElements();
}

TextNoteSubGroup::~TextNoteSubGroup()
{

}

void TextNoteSubGroup::createElements()
{
    auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);

    auto dragElement_1 = new FieldDraggable(this);
    dragElement_1->setCustomData("Drag Me");
    auto mimeData = new QMimeData();
    mimeData->setText("Drag Me");
    dragElement_1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement_1);

    m_elements.append(contentWidget);
}

QList<QWidget*> TextNoteSubGroup::getElements()
{
    return m_elements;
}