#pragma once

#include "ElementFrame.h"

class UnitElement : public ElementFrame
{
    Q_OBJECT

public:
    explicit UnitElement(QWidget *parent = nullptr);
    virtual ~UnitElement();
};