#include "TemperatureResultSubGroup.h"
#include "views/common_components/TitleSelector.h"
#include "views/business_components/draggable/unit_draggable/UnitDraggable.h"
#include "models/model.h"
#include <QJsonObject>
#include <QMimeData>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>

TemperatureResultSubGroup::TemperatureResultSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle(tr("TemperatureMeasurem2Name"));
}

TemperatureResultSubGroup::~TemperatureResultSubGroup()
{
}

QList<QWidget*> TemperatureResultSubGroup::getElements()
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
        temperatureFeatureSelector = new TemperatureFeatureTitleSelector(this);
        temperatureFeatureSelector->setEnabled(false);
        hlayout_1->addWidget(ruleTypeSelector);
        hlayout_1->addWidget(ruleSequenceSpinBox);
        hlayout_1->addWidget(temperatureFeatureSelector);
        contentWidgetLayout->addLayout(hlayout_1);

        dragElement_1 = new FieldDraggable(this);
        setDragElement1Text();
        dragElement_1->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement_1);

        auto hlayout_2 = new QHBoxLayout();
        hlayout_2->setContentsMargins(0, 0, 0, 0);
        hlayout_2->setSpacing(8);
        temperatureDifferenceSelector = new TemperatureDifferenceTitleSelector(this);
        temperatureDifferenceSelector->setEnabled(false);
        hlayout_2->addWidget(temperatureDifferenceSelector);
        ruleSequence2SpinBox = new RuleSequenceTitleSpinBox(this);
        hlayout_2->addWidget(ruleSequence2SpinBox);
        contentWidgetLayout->addLayout(hlayout_2);

        dragElement_2 = new FieldDraggable(this);
        setDragElement2Text();
        dragElement_2->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement_2);

        m_elements.append(contentWidget);

        updateData1();
        connect(ruleTypeSelector, &RuleTypeTitleSelector::currentIndexChanged, this, [=]() {
            updateData1();
            ruleSequenceSpinBox->setEnabled(ruleTypeSelector->getCurrentType() != RuleTypeTitleSelector::G);
            temperatureFeatureSelector->setEnabled(ruleTypeSelector->getCurrentType() != RuleTypeTitleSelector::P);
        });
        connect(ruleSequenceSpinBox, &RuleSequenceTitleSpinBox::valueChanged, this, [=]() { updateData1(); });
        connect(temperatureFeatureSelector, &TemperatureFeatureTitleSelector::currentIndexChanged, this, [=]() { updateData1(); });
        connect(Model::getInstance(), &Model::signalThermalImageIndexChanged, this, [=](int){ updateData1(); });

        updateData2();
        connect(ruleSequence2SpinBox, &TitleSpinBox::valueChanged, this, [=]() { updateData2(); });
        connect(Model::getInstance(), &Model::signalThermalImageIndexChanged, this, [=](int){ updateData2(); });
    }
    return m_elements;
}

bool TemperatureResultSubGroup::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (watched == dragElement_1) {
                setDragElement1MimeData();
            } else if (watched == dragElement_2) {
                setDragElement2MimeData();
            }
        }
    }
    return FieldSubGroup::eventFilter(watched, event);
}

void TemperatureResultSubGroup::setDragElement1Text()
{
    QString text;
    if (ruleTypeSelector->getCurrentType() == RuleTypeTitleSelector::G)
    {
        text = temperatureFeatureSelector->getCurrentTypeDescription().arg(ruleTypeSelector->getCurrentTypeDescription());
    }
    else
    {
        text = temperatureFeatureSelector->getCurrentTypeDescription().arg(ruleTypeSelector->getCurrentTypeDescription().arg(ruleSequenceSpinBox->value()));
    }
    dragElement_1->setText(text);
}

void TemperatureResultSubGroup::setDragElement2Text()
{
    QString text = QString("Dt%1").arg(ruleSequence2SpinBox->value());
    dragElement_2->setText(text);
}

void TemperatureResultSubGroup::setDragElement1MimeData()
{
    QString text;
    auto mimeData = new QMimeData();

    if (ruleTypeSelector->getCurrentType() == RuleTypeTitleSelector::G)
    {
         text = QString("{{rm%1.%2.%3}}").arg(Model::getInstance()->getThermalImageIndex()).arg(ruleTypeSelector->getCurrentTypeProtocal()).arg(temperatureFeatureSelector->getCurrentTypeProtocal());
    }
    else
    {
        if (ruleTypeSelector->getCurrentType() == RuleTypeTitleSelector::P)
        {
            text = QString("{{rm%1.%2%3.tmp}}").arg(Model::getInstance()->getThermalImageIndex()).arg(ruleTypeSelector->getCurrentTypeProtocal()).arg(ruleSequenceSpinBox->value());
        }
        else
        {
            text = QString("{{rm%1.%2%3.%4}}").arg(Model::getInstance()->getThermalImageIndex()).arg(ruleTypeSelector->getCurrentTypeProtocal()).arg(ruleSequenceSpinBox->value()).arg(temperatureFeatureSelector->getCurrentTypeTitle());
        }
    }

    mimeData->setText(text);
    dragElement_1->setMimeData(mimeData);
    qDebug() << "setDragElement1MimeData:" << text;
}

void TemperatureResultSubGroup::setDragElement2MimeData()
{
    QString text = QString("{{rm%1.Dt%2.tmp}}").arg(Model::getInstance()->getThermalImageIndex()).arg(ruleSequence2SpinBox->value()).arg(ruleSequence2SpinBox->value());
    auto mimeData = new QMimeData();
    mimeData->setText(text);
    dragElement_2->setMimeData(mimeData);
    qDebug() << "setDragElement2MimeData:" << text;
}

void TemperatureResultSubGroup::updateData1()
{
    setDragElement1Text();
}

void TemperatureResultSubGroup::updateData2()
{
    setDragElement2Text();
}