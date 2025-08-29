#include "TemplateTitleSelector.h"

TemplateTitleSelector::TemplateTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Template");
    addItems(QStringList() << "None" << "Point Temp" << "Line Temp" << "Area Temp");
}

TemplateTitleSelector::~TemplateTitleSelector()
{

}