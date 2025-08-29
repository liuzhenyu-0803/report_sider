#pragma once

#include "ElementFrame.h"

class FieldDraggableElement : public ElementFrame
{
    Q_OBJECT

public:
    explicit FieldDraggableElement(QWidget *parent = nullptr);
    virtual ~FieldDraggableElement();

protected:
    void paintEvent(QPaintEvent *event) override;
    QMimeData* FieldDraggableElement::getMimeData() const;
};