#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TextNoteDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit TextNoteDraggable(QWidget *parent = nullptr);
    virtual ~TextNoteDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};
