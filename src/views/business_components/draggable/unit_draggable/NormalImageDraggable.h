#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcCheckBox.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class NormalImageDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit NormalImageDraggable(QWidget *parent = nullptr);
    virtual ~NormalImageDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};
