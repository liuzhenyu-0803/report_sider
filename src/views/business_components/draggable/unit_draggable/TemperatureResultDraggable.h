#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TemperatureResultDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit TemperatureResultDraggable(QWidget *parent = nullptr);
    virtual ~TemperatureResultDraggable();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};
