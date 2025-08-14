#pragma once

#include "Element.h"

class UrlsElement : public Element {
    Q_OBJECT

public:
    explicit UrlsElement(class UrlsElementViewModel *viewModel, QWidget *parent = nullptr);
    ~UrlsElement() override;

protected:
    void paintEvent(QPaintEvent *event) override;
};