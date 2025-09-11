#include "TemperatureDifferenceTitleSelector.h"

TemperatureDifferenceTitleSelector::TemperatureDifferenceTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle(tr("TemperatureDifferenName1"));
    addItem(tr("TemperatureDifferenButton"), "");
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
    return tr("TemperatureDifferen1Button");
}
