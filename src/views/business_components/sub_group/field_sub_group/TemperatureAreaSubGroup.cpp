#include "TemperatureAreaSubGroup.h"
#include "views/business_components/draggable/unit_draggable/TemperatureHistogramDraggable.h"
#include "views/business_components/title_combine_widget/TemperatureFeatureTitleSelector.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"
#include "views/business_components/title_combine_widget/ParameterTitleSelector.h"
#include "models/Model.h"
#include <QJsonObject>
#include <QMimeData>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>

TemperatureAreaSubGroup::TemperatureAreaSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle(tr("TemperatureMeasurem3Name"));
}

TemperatureAreaSubGroup::~TemperatureAreaSubGroup()
{

}

QList<QWidget*> TemperatureAreaSubGroup::getElements()
{
    if (m_elements.isEmpty()) {
        auto contentWidget = new QWidget(this);
        auto contentWidgetLayout = new QVBoxLayout(contentWidget);
        contentWidgetLayout->setContentsMargins(0, 0, 0, 0);
        contentWidgetLayout->setSpacing(10);
        
        auto hlayout_1 = new QHBoxLayout();
        hlayout_1->setContentsMargins(0, 0, 0, 0);
        hlayout_1->setSpacing(8);
        ruleTypeSelector = new RuleTypeTitleSelector(this, QList<int>{RuleTypeTitleSelector::G, RuleTypeTitleSelector::P, RuleTypeTitleSelector::L});
        ruleSequenceSpinBox = new RuleSequenceTitleSpinBox(this);
        ruleSequenceSpinBox->setEnabled(false);
        hlayout_1->addWidget(ruleTypeSelector);
        hlayout_1->addWidget(ruleSequenceSpinBox);
        contentWidgetLayout->addLayout(hlayout_1);

        dragElement = new FieldDraggable(this);
        setDragElementText();
        dragElement->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement);

        m_elements.append(contentWidget);

        updateData();
        connect(ruleTypeSelector, &RuleTypeTitleSelector::currentIndexChanged, this, [=]() {
            if (ruleTypeSelector->getCurrentType() == RuleTypeTitleSelector::G)
            {
                ruleSequenceSpinBox->setEnabled(false);
            }
            else
            {
                ruleSequenceSpinBox->setEnabled(true);
            }
            updateData();
        });
        connect(ruleSequenceSpinBox, &RuleSequenceTitleSpinBox::valueChanged, this, [=]() { updateData(); });
        connect(Model::getInstance(), &Model::signalThermalImageIndexChanged, this, [=](int){ updateData(); });
    }
    return m_elements;
}

bool TemperatureAreaSubGroup::eventFilter(QObject *watched, QEvent *event)
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

void TemperatureAreaSubGroup::setDragElementText()
{
    QString text;
    text = QString(tr("%1AreaButton")).arg(ruleTypeSelector->getCurrentTypeDescription().arg(ruleSequenceSpinBox->value()));
    dragElement->setText(text);
}

void TemperatureAreaSubGroup::setDragElementMimeData()
{
    QString text;
    auto mimeData = new QMimeData();
    if (ruleTypeSelector->getCurrentType() == RuleTypeTitleSelector::G)
    {
        text = QString("{{rm%1.%2.ara}}").arg(Model::getInstance()->getThermalImageIndex()).arg(ruleTypeSelector->getCurrentTypeProtocal());
    }
    else
    {
        text = QString("{{rm%1.%2%3.ara}}").arg(Model::getInstance()->getThermalImageIndex()).arg(ruleTypeSelector->getCurrentTypeProtocal()).arg(ruleSequenceSpinBox->value());
    }
    mimeData->setText(text);
    dragElement->setMimeData(mimeData);
    qDebug() << "TemperatureAreaSubGroup::setDragElementMimeData text:" << text;
}

void TemperatureAreaSubGroup::updateData()
{
    setDragElementText();
}