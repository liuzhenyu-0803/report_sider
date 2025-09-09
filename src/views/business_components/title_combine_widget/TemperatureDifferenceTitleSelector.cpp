#include "TemperatureDifferenceTitleSelector.h"

TemperatureDifferenceTitleSelector::TemperatureDifferenceTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle(tr("TemperatureDifferenName1"));
    addItem(tr("TemperatureDifferenName1"), "");
    setEnabled(false);
}

TemperatureDifferenceTitleSelector::~TemperatureDifferenceTitleSelector()
{

}

QString TemperatureDifferenceTitleSelector::getCurrentTypeTitle() const
{
    return "Dt";
}

QString TemperatureDifferenceTitleSelector::getCurrentTypeProtocal() const
{
    return "dt";
}

QString TemperatureDifferenceTitleSelector::getCurrentTypeDescription() const
{
    return tr("TemperatureDifferenceButton");
}
