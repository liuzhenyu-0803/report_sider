#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class NormalImageElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit NormalImageElement(QWidget *parent = nullptr);
    virtual ~NormalImageElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};