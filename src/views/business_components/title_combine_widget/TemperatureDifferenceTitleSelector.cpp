#include "TemperatureDifferenceTitleSelector.h"

TemperatureDifferenceTitleSelector::TemperatureDifferenceTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Temperature Difference");
    addItems(QStringList() << "None" << "Point Temp" << "Line Temp" << "Area Temp");
}

TemperatureDifferenceTitleSelector::~TemperatureDifferenceTitleSelector()
{

}