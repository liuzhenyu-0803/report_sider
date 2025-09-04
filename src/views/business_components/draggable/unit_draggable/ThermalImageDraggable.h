#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcCheckBox.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class ThermalImageDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit ThermalImageDraggable(QWidget *parent = nullptr);
    virtual ~ThermalImageDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    MicroUI::QcCheckBox *m_checkBox = nullptr;
};
