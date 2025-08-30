#include "TemperatureResultSubGroup.h"
#include "views/common_components/TitleSelector.h"
#include "views/common_components/TitleSpinBox.h"
#include "views/business_components/draggable/unit_draggable/UnitDraggable.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"
#include "views/business_components/title_combine_widget/RuleSequenceTitleSpinBox.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureFeatureTitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"


TemperatureResultSubGroup::TemperatureResultSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle("测温结果");
    createElements();
}

TemperatureResultSubGroup::~TemperatureResultSubGroup()
{
}

void TemperatureResultSubGroup::createElements()
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
    auto temperatureFeatureSelector = new TemperatureFeatureTitleSelector(this);
    hlayout_1->addWidget(ruleTypeSelector);
    hlayout_1->addWidget(ruleSequenceSpinBox);
    hlayout_1->addWidget(temperatureFeatureSelector);
    contentWidgetLayout->addLayout(hlayout_1);

    auto dragElement_1 = new FieldDraggable(this);
    dragElement_1->setCustomData("Drag Me");
    auto mimeData = new QMimeData();
    mimeData->setText("Drag Me");
    dragElement_1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement_1);

    auto hlayout_2 = new QHBoxLayout();
    hlayout_2->setContentsMargins(0, 0, 0, 0);
    hlayout_2->setSpacing(8);
    auto temperatureDifferenceSelector = new TemperatureDifferenceTitleSelector(this);
    hlayout_2->addWidget(temperatureDifferenceSelector);
    auto ruleSequence2SpinBox = new TitleSpinBox(this);
    ruleSequence2SpinBox->setTitle("Rule Sequence");
    hlayout_2->addWidget(ruleSequence2SpinBox);
    contentWidgetLayout->addLayout(hlayout_2);

    auto dragElement_2 = new FieldDraggable(this);
    dragElement_2->setCustomData("Drag Me Too");
    auto mimeData2 = new QMimeData();
    mimeData2->setText("Drag Me Too");
    dragElement_2->setMimeData(mimeData2);
    contentWidgetLayout->addWidget(dragElement_2);

    m_elements.append(contentWidget);
}

QList<QWidget*> TemperatureResultSubGroup::getElements()
{
    return m_elements;
}