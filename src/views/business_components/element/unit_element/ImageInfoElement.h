#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class ImageInfoElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit ImageInfoElement(QWidget *parent = nullptr);
    virtual ~ImageInfoElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};