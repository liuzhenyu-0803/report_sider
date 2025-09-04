#include "RuleSequenceTitleSpinBox.h"

RuleSequenceTitleSpinBox::RuleSequenceTitleSpinBox(QWidget *parent)
    : TitleSpinBox(parent)
{
    setTitle("Rule Sequence");

    setRange(1, 100);
    setValue(1);
}

RuleSequenceTitleSpinBox::~RuleSequenceTitleSpinBox()
{
}
