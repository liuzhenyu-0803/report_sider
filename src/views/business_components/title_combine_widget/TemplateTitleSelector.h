#ifndef TEMPLATE_TITLE_SELECTOR_H
#define TEMPLATE_TITLE_SELECTOR_H

#include "views/common_components/TitleSelector.h"

class TemplateTitleSelector : public TitleSelector
{
    Q_OBJECT

public:
    explicit TemplateTitleSelector(QWidget *parent = nullptr);
    ~TemplateTitleSelector();
};

#endif // TEMPLATE_TITLE_SELECTOR_H