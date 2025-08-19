#include "UnitElement.h"
#include "../../models/UnitElementModel.h"

UnitElement::UnitElement(UnitElementModel *model, QWidget *parent)
    : Element(model, parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    // 设置固定大小为100x100
    setFixedSize(100, 100);
    // 启用鼠标跟踪
    setMouseTracking(true);
}

UnitElement::~UnitElement() = default;