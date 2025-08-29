#ifndef TEMPERATUREFEATURETITLESELECTOR_H
#define TEMPERATUREFEATURETITLESELECTOR_H

#include "views/common_components/TitleSelector.h"

class TemperatureFeatureTitleSelector : public TitleSelector
{
    Q_OBJECT

public:
    explicit TemperatureFeatureTitleSelector(QWidget *parent = nullptr);
    ~TemperatureFeatureTitleSelector();
};

#endif // TEMPERATUREFEATURETITLESELECTOR_H