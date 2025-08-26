#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class InstrumentInfoElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit InstrumentInfoElement(QWidget *parent = nullptr);
    virtual ~InstrumentInfoElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};