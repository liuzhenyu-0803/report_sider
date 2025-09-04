#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class GeographicInfoDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit GeographicInfoDraggable(QWidget *parent = nullptr);
    virtual ~GeographicInfoDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};