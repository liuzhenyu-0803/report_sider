#pragma once

#include "Element.h"

class ImageElement : public Element {
    Q_OBJECT

public:
    explicit ImageElement(class ImageElementViewModel *viewModel, QWidget *parent = nullptr);
    ~ImageElement() override;

protected:
    void paintEvent(QPaintEvent *event) override;
};