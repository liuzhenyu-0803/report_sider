#include "TemperatureParametersSubGroup.h"
#include "views/common_components/TitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureFeatureTitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"
#include "models/Model.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMimeData>
#include <QWidget>
#include <QJsonObject>
#include <QEvent>
#include <QMouseEvent>

TemperatureParametersSubGroup::TemperatureParametersSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle(tr("TemperatureMeasuremName1"));
}

TemperatureParametersSubGroup::~TemperatureParametersSubGroup()
{
}

QList<QWidget*> TemperatureParametersSubGroup::getElements()
{
    if (m_elements.isEmpty()) {
        auto contentWidget = new QWidget(this);
        auto contentWidgetLayout = new QVBoxLayout(contentWidget);
        contentWidgetLayout->setContentsMargins(0, 0, 0, 0);
        contentWidgetLayout->setSpacing(10);
        
        auto hlayout_1 = new QHBoxLayout();
        hlayout_1->setContentsMargins(0, 0, 0, 0);
        hlayout_1->setSpacing(8);
        ruleTypeSelector = new RuleTypeTitleSelector(this);
        ruleSequenceSpinBox = new RuleSequenceTitleSpinBox(this);
        ruleSequenceSpinBox->setEnabled(false);
        parameterFeatureSelector = new ParameterTitleSelector(this);
        hlayout_1->addWidget(ruleTypeSelector);
        hlayout_1->addWidget(ruleSequenceSpinBox);
        hlayout_1->addWidget(parameterFeatureSelector);
        contentWidgetLayout->addLayout(hlayout_1);

        dragElement = new FieldDraggable(this);
        dragElement->setCustomData(QJsonObject{{"text", "Drag Me"}});
        setDragElementText();
        dragElement->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement);

        m_elements.append(contentWidget);
        
        updateData();
        connect(ruleTypeSelector, &RuleTypeTitleSelector::currentIndexChanged, this, [=]() {
            updateData();
            ruleSequenceSpinBox->setEnabled(ruleTypeSelector->getCurrentType() != RuleTypeTitleSelector::G);
        });

        connect(ruleSequenceSpinBox, &RuleSequenceTitleSpinBox::valueChanged, this, [=]() { updateData(); });
        connect(parameterFeatureSelector, &ParameterTitleSelector::currentIndexChanged, this, [=]() { updateData(); });
        connect(Model::getInstance(), &Model::signalThermalImageIndexChanged, this, [=](int){ updateData(); });
    }
    return m_elements;
}

bool TemperatureParametersSubGroup::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (watched == dragElement) {
                setDragElementMimeData();
            }
        }
    }
    return FieldSubGroup::eventFilter(watched, event);
}

void TemperatureParametersSubGroup::setDragElementText()
{
    QString text;
    if (parameterFeatureSelector->getCurrentType() == ParameterTitleSelector::Emissivity || parameterFeatureSelector->getCurrentType() == ParameterTitleSelector::Distance || parameterFeatureSelector->getCurrentType() == ParameterTitleSelector::ReflectedTemp)
    {
        if (ruleTypeSelector->getCurrentType() == RuleTypeTitleSelector::G)
        {
            text = parameterFeatureSelector->getCurrentTypeDescription().arg(ruleTypeSelector->getCurrentTypeDescription());
        }
        else
        {
            text = parameterFeatureSelector->getCurrentTypeDescription().arg(ruleTypeSelector->getCurrentTypeDescription().arg(ruleSequenceSpinBox->value()));
        }
    }
    else
    {
        text = parameterFeatureSelector->getCurrentTypeDescription();
    }
    dragElement->setText(text);
}

void TemperatureParametersSubGroup::setDragElementMimeData()
{
    QString text;
    auto mimeData = new QMimeData();
    if (parameterFeatureSelector->getCurrentType() == ParameterTitleSelector::Emissivity || parameterFeatureSelector->getCurrentType() == ParameterTitleSelector::Distance || parameterFeatureSelector->getCurrentType() == ParameterTitleSelector::ReflectedTemp)
    {
        if (ruleTypeSelector->getCurrentType() == RuleTypeTitleSelector::G)
        {
            text = QString("n:rm%1.G.%2").arg(Model::getInstance()->getThermalImageIndex()).arg(parameterFeatureSelector->getCurrentTypeProtocal());
        }
        else
        {
            text = QString("n:rm%1.%2%3.%4").arg(Model::getInstance()->getThermalImageIndex()).arg(ruleTypeSelector->getCurrentTypeProtocal()).arg(ruleSequenceSpinBox->value()).arg(parameterFeatureSelector->getCurrentTypeProtocal());
        }
    }
    else
    {
        text = QString("n:rm%1.%2").arg(Model::getInstance()->getThermalImageIndex()).arg(parameterFeatureSelector->getCurrentTypeProtocal());
    }
    mimeData->setText(text);
    dragElement->setMimeData(mimeData);
}

void TemperatureParametersSubGroup::updateData()
{
    setDragElementText();
}