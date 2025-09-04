#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class QrCodeNoteDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit QrCodeNoteDraggable(QWidget *parent = nullptr);
    virtual ~QrCodeNoteDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};
