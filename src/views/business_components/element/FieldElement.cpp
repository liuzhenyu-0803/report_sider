#include "FieldElement.h"

FieldElement::FieldElement(QWidget *parent)
    : ElementFrame(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setFixedSize(100, 100);
    setMouseTracking(true);
}

FieldElement::~FieldElement() = default;