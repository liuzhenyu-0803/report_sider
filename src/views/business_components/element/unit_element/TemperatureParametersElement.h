#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TemperatureParametersElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit TemperatureParametersElement(QWidget *parent = nullptr);
    virtual ~TemperatureParametersElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};