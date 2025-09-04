#pragma once

#include "views/business_components/draggable/Draggable.h"

class FieldDraggable : public Draggable
{
    Q_OBJECT

public:
    explicit FieldDraggable(QWidget *parent = nullptr);
    virtual ~FieldDraggable();

    // 设置文本内容
    void setText(const QString& text);

protected:    
    void paintEvent(QPaintEvent *event) override;
};