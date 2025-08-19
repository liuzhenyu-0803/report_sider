#pragma once

#include "Element.h"

class UnitElementModel;

class UnitElement : public Element
{
    Q_OBJECT

public:
    explicit UnitElement(UnitElementModel *model, QWidget *parent = nullptr);
    virtual ~UnitElement();
};