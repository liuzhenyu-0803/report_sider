#include "ParameterTitleSelector.h"

ParameterTitleSelector::ParameterTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Parameter");

    addItem(tr("Emissivity"), Emissivity);
    addItem(tr("Distance"), Distance);
    addItem(tr("Reflected Temperature"), ReflectedTemp);
    addItem(tr("Atmospheric Temperature"), AtmosphericTemp);
    addItem(tr("Humidity"), Humidity);
}

ParameterTitleSelector::~ParameterTitleSelector()
{

}

int ParameterTitleSelector::getCurrentType() const
{
    return currentData().toInt();
}

QString ParameterTitleSelector::getCurrentTypeText() const
{
    return getTypeString(getCurrentType());
}

QString ParameterTitleSelector::getCurrentTypeProtocal() const
{
    return getTypeProtocal(getCurrentType());
}

QString ParameterTitleSelector::getTypeString(int type) const
{
    switch (type)
    {
    case Emissivity:
        return "Emissivity";
    case Distance:
        return "Distance";
    case ReflectedTemp:
        return "Reflected Temperature";
    case AtmosphericTemp:
        return "Atmospheric Temperature";
    case Humidity:
        return "Humidity";
    default:
        return "Unknown";
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