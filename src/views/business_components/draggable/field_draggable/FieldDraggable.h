#pragma once

#include "views/business_components/draggable/Draggable.h"

class FieldDraggable : public Draggable
{
    Q_OBJECT

public:
    explicit FieldDraggable(QWidget *parent = nullptr);
    virtual ~FieldDraggable();

protected:
    void paintEvent(QPaintEvent *event) override;
    QMimeData* getMimeData() const override;
};