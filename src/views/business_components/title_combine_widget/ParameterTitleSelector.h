#ifndef PARAMETERTITLESELECTOR_H
#define PARAMETERTITLESELECTOR_H

#include "views/common_components/TitleSelector.h"

class ParameterTitleSelector : public TitleSelector
{
    Q_OBJECT

public:
    enum ParameterType
    {
        Emissivity,
        Distance,
        ReflectedTemp,
        AtmosphericTemp,
        Humidity,
    };

    explicit ParameterTitleSelector(QWidget *parent = nullptr);
    ~ParameterTitleSelector();

    int getCurrentType() const;
    QString getCurrentTypeTitle() const;
    QString getCurrentTypeDescription() const;
    QString getCurrentTypeProtocal() const;
    QString getTypeTitle(int type) const;
    QString getTypeDescription(int type) const;
    QString getTypeProtocal(int type) const;
};

#endif // PARAMETERTITLESELECTOR_H