#ifndef TEMPERATUREPARAMETERSSUBGROUP_H
#define TEMPERATUREPARAMETERSSUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/business_components/title_combine_widget/RuleSequenceTitleSpinBox.h"
#include "views/business_components/title_combine_widget/ParameterTitleSelector.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"

class TemperatureParametersSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TemperatureParametersSubGroup(QWidget *parent = nullptr);
    virtual ~TemperatureParametersSubGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void setDragElementText();
    void setDragElementMimeData();
    void updateData();
    
    QList<QWidget*> m_elements;
    
    RuleTypeTitleSelector *ruleTypeSelector;
    RuleSequenceTitleSpinBox *ruleSequenceSpinBox;
    ParameterTitleSelector *parameterFeatureSelector;
    FieldDraggable *dragElement;
};

#endif // TEMPERATUREPARAMETERSSUBGROUP_H
