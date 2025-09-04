#ifndef TEMPERATURERESULTSUBGROUP_H
#define TEMPERATURERESULTSUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/business_components/title_combine_widget/RuleSequenceTitleSpinBox.h"
#include "views/business_components/title_combine_widget/TemperatureFeatureTitleSelector.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"
#include "views/business_components/title_combine_widget/TemperatureDifferenceTitleSelector.h"
#include "views/common_components/TitleSpinBox.h"

class TemperatureResultSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TemperatureResultSubGroup(QWidget *parent = nullptr);
    virtual ~TemperatureResultSubGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void setDragElement1Text();
    void setDragElement2Text();
    void setDragElement1MimeData();
    void setDragElement2MimeData();
    void updateData1();
    void updateData2();

    QList<QWidget*> m_elements;

    RuleTypeTitleSelector *ruleTypeSelector;
    RuleSequenceTitleSpinBox *ruleSequenceSpinBox;
    TemperatureFeatureTitleSelector *temperatureFeatureSelector;
    FieldDraggable *dragElement_1;
    TemperatureDifferenceTitleSelector *temperatureDifferenceSelector;
    RuleSequenceTitleSpinBox *ruleSequence2SpinBox;
    FieldDraggable *dragElement_2;
};

#endif // TEMPERATURERESULTSUBGROUP_H
