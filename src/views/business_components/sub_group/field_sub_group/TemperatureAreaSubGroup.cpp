#include "TemperatureAreaSubGroup.h"
#include "views/business_components/draggable/unit_draggable/TemperatureHistogramDraggable.h"
#include "views/business_components/title_combine_widget/RuleSequenceTitleSpinBox.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureFeatureTitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"
#include "views/business_components/title_combine_widget/ParameterTitleSelector.h"

TemperatureAreaSubGroup::TemperatureAreaSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("测温面积");
    createElements();
}

TemperatureAreaSubGroup::~TemperatureAreaSubGroup()
{
}

void TemperatureAreaSubGroup::createElements()
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

    auto dragElement = new FieldDraggable(this);
    dragElement->setCustomData("Drag Me");
    auto mimeData = new QMimeData();
    mimeData->setText("Drag Me");
    dragElement->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement);

    m_elements.append(contentWidget);
}

QList<QWidget*> TemperatureAreaSubGroup::getElements()
{
    return m_elements;
}