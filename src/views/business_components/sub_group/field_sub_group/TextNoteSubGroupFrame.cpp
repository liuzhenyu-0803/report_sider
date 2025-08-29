#include "TextNoteSubGroupFrame.h"
#include "views/business_components/element/unit_element/TextNoteElement.h"
#include "views/common_components/TitleSelector.h"
#include "views/common_components/TitleSpinBox.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"
#include "views/business_components/element/UnitElementFrame.h"

TextNoteSubGroupFrame::TextNoteSubGroupFrame(QWidget *parent)
    : FieldSubGroupFrame(parent)
{
    setGroupTitle("Text Note");
    createElements();
}

TextNoteSubGroupFrame::~TextNoteSubGroupFrame()
{

}

void TextNoteSubGroupFrame::createElements()
{
    auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);

    auto dragElement_1 = new FieldDraggableElement(this);
    dragElement_1->setCustomData("Drag Me");
    auto mimeData = new QMimeData();
    mimeData->setText("Drag Me");
    dragElement_1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement_1);

    m_elements.append(contentWidget);
}

QList<QWidget*> TextNoteSubGroupFrame::getElements()
{
    return m_elements;
}