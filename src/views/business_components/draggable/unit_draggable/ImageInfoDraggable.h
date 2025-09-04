#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcCheckBox.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class ImageInfoDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit ImageInfoDraggable(QWidget *parent = nullptr);
    virtual ~ImageInfoDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    MicroUI::QcCheckBox *m_checkBox = nullptr;
};
