#pragma once

#include "ElementFrame.h"

class FieldElement : public ElementFrame
{
    Q_OBJECT

public:
    explicit FieldElement(QWidget *parent = nullptr);
    virtual ~FieldElement();
};