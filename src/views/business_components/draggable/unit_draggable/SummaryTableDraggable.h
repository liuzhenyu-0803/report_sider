#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class SummaryTableDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit SummaryTableDraggable(QWidget *parent = nullptr);
    virtual ~SummaryTableDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};