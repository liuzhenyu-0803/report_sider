#include "ParameterTitleSelector.h"

ParameterTitleSelector::ParameterTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Parameter");
    addItems(QStringList() << "None" << "Point Temp" << "Line Temp" << "Area Temp");
}

ParameterTitleSelector::~ParameterTitleSelector()
{

}