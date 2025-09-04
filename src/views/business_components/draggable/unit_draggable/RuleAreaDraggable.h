#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class RuleAreaDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit RuleAreaDraggable(QWidget *parent = nullptr);
    virtual ~RuleAreaDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};