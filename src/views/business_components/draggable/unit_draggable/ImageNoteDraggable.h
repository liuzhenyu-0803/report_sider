#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class ImageNoteDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit ImageNoteDraggable(QWidget *parent = nullptr);
    virtual ~ImageNoteDraggable();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};
