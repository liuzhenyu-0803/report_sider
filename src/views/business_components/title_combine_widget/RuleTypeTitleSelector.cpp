#include "RuleTypeTitleSelector.h"

RuleTypeTitleSelector::RuleTypeTitleSelector(QWidget *parent, QList<int> filterTypes)
    : TitleSelector(parent)
{
    setTitle(tr("RuleTypeName"));
    
    if (!filterTypes.contains(G))
        addItem(getTypeName(G), G);
    if (!filterTypes.contains(P))
        addItem(getTypeName(P), P);
    if (!filterTypes.contains(L))
        addItem(getTypeName(L), L);
    if (!filterTypes.contains(Fl))
        addItem(getTypeName(Fl), Fl);
    if (!filterTypes.contains(R))
        addItem(getTypeName(R), R);
    if (!filterTypes.contains(Ep))
        addItem(getTypeName(Ep), Ep);
    if (!filterTypes.contains(Po))
        addItem(getTypeName(Po), Po);
}

RuleTypeTitleSelector::~RuleTypeTitleSelector()
{

}

int RuleTypeTitleSelector::getCurrentType() const
{
    return currentData().toInt();
}

QString RuleTypeTitleSelector::getCurrentTypeProtocal() const
{
    return getTypeProtocal(getCurrentType());
}

QString RuleTypeTitleSelector::getTypeName(int type) const
{
    switch (type) {
    case G:
        return tr("Global(G)Button");
    case P:
        return tr("Point(P)Button");
    case L:
        return tr("Line(L)Button");
    case Fl:
        return tr("BrokenLine(Fl)Button");
    case R:
        return tr("Rectangle(R)Button");
    case Ep:
        return tr("Ellipse(Ep)Button");
    case Po:
        return tr("Polygon(Po)Button");
    default:
        return QString();
    }
}

QString RuleTypeTitleSelector::getCurrentTypeDescription() const
{
    return getTypeDescription(getCurrentType());
}

QString RuleTypeTitleSelector::getTypeProtocal(int type) const
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

QString RuleTypeTitleSelector::getTypeDescription(int type) const
{
    switch (type) {
    case G:
        return tr("Global(G)Button");
    case P:
        return tr("Point(P%1)Button");
    case L:
        return tr("Line(L%1)Button");
    case Fl:
        return tr("Line(Fl%1)Button");
    case R:
        return tr("Rectangle(R%1)Button");
    case Ep:
        return tr("Ellipse(Ep%1)Button");
    case Po:
        return tr("Polygon(Po%1)Button");
    default:
        return QString();
    }
}
