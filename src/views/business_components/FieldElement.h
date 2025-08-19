#pragma once

#include "Element.h"

class FieldElementModel;

class FieldElement : public Element
{
    Q_OBJECT

public:
    explicit FieldElement(FieldElementModel *model, QWidget *parent = nullptr);
    virtual ~FieldElement();
};