#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class NormalImageDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit NormalImageDraggable(QWidget *parent = nullptr);
    virtual ~NormalImageDraggable();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};
