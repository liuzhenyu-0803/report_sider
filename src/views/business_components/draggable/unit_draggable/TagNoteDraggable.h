#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcRadioButton.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TagNoteDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit TagNoteDraggable(QWidget *parent = nullptr);
    virtual ~TagNoteDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    MicroUI::QcRadioButton *m_radio1Button = nullptr;
    MicroUI::QcRadioButton *m_radio2Button = nullptr;
};
