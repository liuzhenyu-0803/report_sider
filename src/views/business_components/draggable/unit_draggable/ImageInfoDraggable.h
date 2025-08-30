#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
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
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};
