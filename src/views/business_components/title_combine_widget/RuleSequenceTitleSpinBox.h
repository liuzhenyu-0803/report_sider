#ifndef RULESEQUENCETITLESPINBOX_H
#define RULESEQUENCETITLESPINBOX_H

#include "views/common_components/TitleSpinBox.h"


class RuleSequenceTitleSpinBox : public TitleSpinBox
{
    Q_OBJECT

public:
    explicit RuleSequenceTitleSpinBox(QWidget *parent = nullptr);
    ~RuleSequenceTitleSpinBox();

};

#endif // RULESEQUENCETITLESPINBOX_H