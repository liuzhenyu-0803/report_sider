#include "TemperatureFeatureTitleSelector.h"

TemperatureFeatureTitleSelector::TemperatureFeatureTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Temperature Feature");
    addItems(QStringList() << "None" << "Point Temp" << "Line Temp" << "Area Temp");
}

TemperatureFeatureTitleSelector::~TemperatureFeatureTitleSelector()
{

}