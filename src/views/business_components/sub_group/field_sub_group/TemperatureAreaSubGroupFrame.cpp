#include "TemperatureAreaSubGroupFrame.h"
#include "views/business_components/element/unit_element/TemperatureHistogramElement.h"
#include "views/business_components/title_combine_widget/RuleSequenceTitleSpinBox.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureFeatureTitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"
#include "views/business_components/title_combine_widget/ParameterTitleSelector.h"

TemperatureAreaSubGroupFrame::TemperatureAreaSubGroupFrame(QWidget *parent)
    : FieldSubGroupFrame(parent)
{
    setGroupTitle("测温面积");
    createElements();
}

TemperatureAreaSubGroupFrame::~TemperatureAreaSubGroupFrame()
{
}

void TemperatureAreaSubGroupFrame::createElements()
{
        auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);
    
    auto hlayout_1 = new QHBoxLayout();
    hlayout_1->setContentsMargins(0, 0, 0, 0);
    hlayout_1->setSpacing(8);
    auto ruleTypeSelector = new RuleTypeTitleSelector(this);
    auto ruleSequenceSpinBox = new RuleSequenceTitleSpinBox(this);
    hlayout_1->addWidget(ruleTypeSelector);
    hlayout_1->addWidget(ruleSequenceSpinBox);
    contentWidgetLayout->addLayout(hlayout_1);

    auto dragElement = new FieldDraggableElement(this);
    dragElement->setCustomData("Drag Me");
    auto mimeData = new QMimeData();
    mimeData->setText("Drag Me");
    dragElement->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement);

    m_elements.append(contentWidget);
}

QList<QWidget*> TemperatureAreaSubGroupFrame::getElements()
{
    return m_elements;
}