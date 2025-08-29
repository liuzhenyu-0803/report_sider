#include "RuleTypeTitleSelector.h"

RuleTypeTitleSelector::RuleTypeTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Rule Type");
    addItems(QStringList() << "None" << "Point Temp" << "Line Temp" << "Area Temp");
}

RuleTypeTitleSelector::~RuleTypeTitleSelector()
{

}