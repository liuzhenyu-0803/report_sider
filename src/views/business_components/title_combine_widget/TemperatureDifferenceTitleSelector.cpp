#include "TemperatureDifferenceTitleSelector.h"

TemperatureDifferenceTitleSelector::TemperatureDifferenceTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Temperature Difference");
    addItem(("Temperature Difference"), "");
    setEnabled(false);
}

TemperatureDifferenceTitleSelector::~TemperatureDifferenceTitleSelector()
{

}

QString TemperatureDifferenceTitleSelector::getCurrentTypeText() const
{
    return "Dt";
}

QString TemperatureDifferenceTitleSelector::getCurrentTypeProtocal() const
{
    return "dt";
}