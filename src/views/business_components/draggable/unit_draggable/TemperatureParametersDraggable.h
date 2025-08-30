#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TemperatureParametersDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit TemperatureParametersDraggable(QWidget *parent = nullptr);
    virtual ~TemperatureParametersDraggable();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};
