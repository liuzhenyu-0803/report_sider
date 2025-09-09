#include "ParameterTitleSelector.h"

ParameterTitleSelector::ParameterTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle(tr("ParametersName"));

    addItem(getTypeTitle(Emissivity), Emissivity);
    addItem(getTypeTitle(Distance), Distance);
    addItem(getTypeTitle(ReflectedTemp), ReflectedTemp);
    addItem(getTypeTitle(AtmosphericTemp), AtmosphericTemp);
    addItem(getTypeTitle(Humidity), Humidity);
}

ParameterTitleSelector::~ParameterTitleSelector()
{

}

int ParameterTitleSelector::getCurrentType() const
{
    return currentData().toInt();
}

QString ParameterTitleSelector::getCurrentTypeTitle() const
{
    return getTypeProtocal(getCurrentType());
}

QString ParameterTitleSelector::getCurrentTypeDescription() const
{
    return getTypeDescription(getCurrentType());
}

QString ParameterTitleSelector::getCurrentTypeProtocal() const
{
    return getTypeProtocal(getCurrentType());
}

QString ParameterTitleSelector::getTypeTitle(int type) const
{
    switch (type)
    {
    case Emissivity:
        return tr("EmissivityButton");
    case Distance:
        return tr("DistanceButton");
    case ReflectedTemp:
        return tr("ReflectedTemperaturButton");
    case AtmosphericTemp:
        return tr("AmbientTemperatureButton");
    case Humidity:
        return tr("EnvironmentalHumidiButton");
    default:
        return "Unknown";
    }
}

QString ParameterTitleSelector::getTypeDescription(int type) const
{
    switch (type)
    {
        case Emissivity:
            return tr("%1EmissivityButton");
        case Distance:
            return tr("%1DistanceButton");
        case ReflectedTemp:
            return tr("%1ReflectiveTemperButton");
        case AtmosphericTemp:
            return tr("%1AmbientTemperatuButton");
        case Humidity:
            return tr("%1EnvironmentalHumButton");
        default:
            return QString();
    }
}

QString ParameterTitleSelector::getTypeProtocal(int type) const
{
    switch (type)
    {
    case Emissivity:
        return "ems";
    case Distance:
        return "dstr";
    case ReflectedTemp:
        return "rft";
    case AtmosphericTemp:
        return "atm";
    case Humidity:
        return "hum";
    default:
        return "unknown";
    }
}