#pragma once

#include "Element.h"

// 前置声明Model类
class ElementModel;

class ElementFrame : public Element
{
    Q_OBJECT

public:
    explicit ElementFrame(ElementModel *model, QWidget *parent = nullptr);
    ~ElementFrame() override;
};