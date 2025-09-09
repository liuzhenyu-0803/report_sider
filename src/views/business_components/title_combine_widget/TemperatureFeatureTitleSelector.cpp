#include "TemperatureFeatureTitleSelector.h"

TemperatureFeatureTitleSelector::TemperatureFeatureTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle(tr("TemperatureCharacteName"));
    addItem(getTypeTitle(Max), Max);
    addItem(getTypeTitle(Min), Min);
    addItem(getTypeTitle(Avg), Avg);
    // addItem(getTypeString(Center), Center);
}

TemperatureFeatureTitleSelector::~TemperatureFeatureTitleSelector()
{

}

int TemperatureFeatureTitleSelector::getCurrentType() const
{
    return currentData().toInt();
}

QString TemperatureFeatureTitleSelector::getCurrentTypeTitle() const
{
    return getTypeTitle(getCurrentType());
}

QString TemperatureFeatureTitleSelector::getCurrentTypeDescription() const
{
    return getTypeDescription(getCurrentType());
}

QString TemperatureFeatureTitleSelector::getCurrentTypeProtocal() const
{
    return getTypeProtocal(getCurrentType());
}

QString TemperatureFeatureTitleSelector::getTypeTitle(int type) const
{
    switch (type) 
    {
        case Max:
            return tr("MaximumTemperatureButton");
        case Min:
            return tr("MinimumTemperatureButton");
        case Avg:
            return tr("AverageTemperatureButton");
        // case Center:
        //     return tr("Center");
        default:
            return QString();
    }
}

QString TemperatureFeatureTitleSelector::getTypeProtocal(int type) const
{
    switch (type) 
    {
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

QString TemperatureFeatureTitleSelector::getTypeDescription(int type) const
{
    if (!isEnabled())
    {
        return tr("%1TemperatureButton");
    }

    switch (type) 
    {
        case Max:
            return tr("%1MaximumTemperatuButton");
        case Min:
            return tr("%1LowestTemperaturButton");
        case Avg:
            return tr("%1AverageTemperatuButton");
        case Center:
            return tr("%1CoreTemperatureButton");
        default:
            return QString();
    }
}
