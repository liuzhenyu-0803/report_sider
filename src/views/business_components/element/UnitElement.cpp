#include "UnitElement.h"

UnitElement::UnitElement(QWidget *parent)
    : ElementFrame(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    setFixedSize(100, 100);
    setMouseTracking(true);
}

UnitElement::~UnitElement() = default;