#ifndef TEMPERATUREAREASUBGROUP_H
#define TEMPERATUREAREASUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/business_components/title_combine_widget/RuleSequenceTitleSpinBox.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"

class TemperatureAreaSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TemperatureAreaSubGroup(QWidget *parent = nullptr);
    virtual ~TemperatureAreaSubGroup();

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
    FieldDraggable *dragElement;
};

#endif // TEMPERATUREAREASUBGROUP_H
