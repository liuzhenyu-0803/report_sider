#pragma once

#include "Element.h"

class HtmlElement : public Element {
    Q_OBJECT

public:
    explicit HtmlElement(class HtmlElementViewModel *viewModel, QWidget *parent = nullptr);
    ~HtmlElement() override;

protected:
    void paintEvent(QPaintEvent *event) override;
};