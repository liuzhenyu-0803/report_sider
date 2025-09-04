#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class CoverTableDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit CoverTableDraggable(QWidget *parent = nullptr);
    virtual ~CoverTableDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};