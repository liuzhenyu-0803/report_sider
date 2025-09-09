#include "RuleSequenceTitleSpinBox.h"

RuleSequenceTitleSpinBox::RuleSequenceTitleSpinBox(QWidget *parent)
    : TitleSpinBox(parent)
{
    setTitle(tr("RuleNumberName"));

    setRange(1, 100);
    setValue(1);
}

RuleSequenceTitleSpinBox::~RuleSequenceTitleSpinBox()
{
}
