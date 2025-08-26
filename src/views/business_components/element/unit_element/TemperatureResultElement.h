#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TemperatureResultElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit TemperatureResultElement(QWidget *parent = nullptr);
    virtual ~TemperatureResultElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};