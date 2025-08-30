#include "TagNoteSubGroup.h"
#include "views/business_components/title_combine_widget/TemplateTitleSelector.h"

TagNoteSubGroup::TagNoteSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("标签备注");
    createElements();
}

TagNoteSubGroup::~TagNoteSubGroup()
{
}

void TagNoteSubGroup::createElements()
{
    auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);

    auto templateSelector = new TemplateTitleSelector(this);
    contentWidgetLayout->addWidget(templateSelector);

    auto dragElement_1 = new FieldDraggable(this);
    dragElement_1->setCustomData("Drag Me");
    auto mimeData = new QMimeData();
    mimeData->setText("Drag Me");
    dragElement_1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement_1);

    m_elements.append(contentWidget);
}

QList<QWidget*> TagNoteSubGroup::getElements()
{
    return m_elements;
}