#include "TemperatureFeatureTitleSelector.h"

TemperatureFeatureTitleSelector::TemperatureFeatureTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Temperature Feature");
    addItem(getTypeString(Max), Max);
    addItem(getTypeString(Min), Min);
    addItem(getTypeString(Avg), Avg);
    addItem(getTypeString(Center), Center);
}

TemperatureFeatureTitleSelector::~TemperatureFeatureTitleSelector()
{

}

int TemperatureFeatureTitleSelector::getCurrentType() const
{
    return currentData().toInt();
}

QString TemperatureFeatureTitleSelector::getCurrentTypeText() const
{
    return getTypeString(getCurrentType());
}

QString TemperatureFeatureTitleSelector::getCurrentTypeProtocal() const
{
    return getTypeProtocal(getCurrentType());
}

QString TemperatureFeatureTitleSelector::getTypeString(int type) const
{
    switch (type) {
    case Max:
        return tr("Max");
    case Min:
        return tr("Min");
    case Avg:
        return tr("Avg");
    case Center:
        return tr("Center");
    default:
        return QString();
    }
}

QString TemperatureFeatureTitleSelector::getTypeProtocal(int type) const
{
    switch (type) {
    case Max:
        return "maxT";
    case Min:
        return "minT";
    case Avg:
        return "avgT";
    case Center:
        return "cntT";
    default:
        return QString();
    }
}
