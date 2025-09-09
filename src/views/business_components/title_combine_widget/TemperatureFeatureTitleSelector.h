#ifndef TEMPERATUREFEATURETITLESELECTOR_H
#define TEMPERATUREFEATURETITLESELECTOR_H

#include "views/common_components/TitleSelector.h"

class TemperatureFeatureTitleSelector : public TitleSelector
{
    Q_OBJECT

public:
    enum TemperatureFeatureType
    {
        Max,
        Min,
        Avg,
        Center,
    };

    explicit TemperatureFeatureTitleSelector(QWidget *parent = nullptr);
    ~TemperatureFeatureTitleSelector();

    int getCurrentType() const;
    QString getCurrentTypeTitle() const;
    QString getCurrentTypeDescription() const;
    QString getCurrentTypeProtocal() const;
    QString getTypeTitle(int type) const;
    QString getTypeDescription(int type) const;
    QString getTypeProtocal(int type) const;
};

#endif // TEMPERATUREFEATURETITLESELECTOR_H