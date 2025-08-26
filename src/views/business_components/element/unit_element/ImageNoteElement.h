#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class ImageNoteElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit ImageNoteElement(QWidget *parent = nullptr);
    virtual ~ImageNoteElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};