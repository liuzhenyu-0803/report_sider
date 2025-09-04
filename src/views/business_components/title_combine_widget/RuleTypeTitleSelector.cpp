#include "RuleTypeTitleSelector.h"

RuleTypeTitleSelector::RuleTypeTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Rule Type");
    addItem("Global", G);
    addItem("Point Rule (P)", P);
    addItem("Line (L)", L);
    addItem("Broken Line (FL)", Fl);
    addItem("Rectangle (R)", R);
    addItem("Ellipse (Ep)", Ep);
    addItem("Polygon (Po)", Po);
}

RuleTypeTitleSelector::~RuleTypeTitleSelector()
{

}

int RuleTypeTitleSelector::getCurrentType() const
{
    return currentData().toInt();
}

QString RuleTypeTitleSelector::getCurrentTypeText() const
{
    return getTypeString(getCurrentType());
}

QString RuleTypeTitleSelector::getTypeString(int type) const
{
    switch (type) {
    case G:
        return "G";
    case P:
        return "P";
    case L:
        return "L";
    case Fl:
        return "Fl";
    case R:
        return "R";
    case Ep:
        return "Ep";
    case Po:
        return "Po";
    default:
        return QString();
    }
}
