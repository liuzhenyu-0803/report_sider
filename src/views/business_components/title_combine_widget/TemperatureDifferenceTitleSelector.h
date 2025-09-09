#ifndef TEMPERATUREDIFFERENCETITLESELECTOR_H
#define TEMPERATUREDIFFERENCETITLESELECTOR_H

#include "views/common_components/TitleSelector.h"

class TemperatureDifferenceTitleSelector : public TitleSelector
{
    Q_OBJECT

public:
    explicit TemperatureDifferenceTitleSelector(QWidget *parent = nullptr);
    ~TemperatureDifferenceTitleSelector();

    QString getCurrentTypeTitle() const;
    QString getCurrentTypeDescription() const;
    QString getCurrentTypeProtocal() const;
};

#endif // TEMPERATUREDIFFERENCETITLESELECTOR_H