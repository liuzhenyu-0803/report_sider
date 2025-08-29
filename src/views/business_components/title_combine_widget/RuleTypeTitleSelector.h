#ifndef RULETYPETITLESELECTOR_H
#define RULETYPETITLESELECTOR_H

#include "views/common_components/TitleSelector.h"

class RuleTypeTitleSelector : public TitleSelector
{
    Q_OBJECT

public:
    explicit RuleTypeTitleSelector(QWidget *parent = nullptr);
    ~RuleTypeTitleSelector();
};

#endif // RULETYPETITLESELECTOR_H