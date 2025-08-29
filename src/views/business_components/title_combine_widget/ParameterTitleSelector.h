#ifndef PARAMETERTITLESELECTOR_H
#define PARAMETERTITLESELECTOR_H

#include "views/common_components/TitleSelector.h"

class ParameterTitleSelector : public TitleSelector
{
    Q_OBJECT

public:
    explicit ParameterTitleSelector(QWidget *parent = nullptr);
    ~ParameterTitleSelector();
};

#endif // PARAMETERTITLESELECTOR_H