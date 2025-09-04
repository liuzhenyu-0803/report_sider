#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TemperatureDifferenceStandardDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit TemperatureDifferenceStandardDraggable(QWidget *parent = nullptr);
    virtual ~TemperatureDifferenceStandardDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};