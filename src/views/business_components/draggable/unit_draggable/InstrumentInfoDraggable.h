#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class InstrumentInfoDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit InstrumentInfoDraggable(QWidget *parent = nullptr);
    virtual ~InstrumentInfoDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};
