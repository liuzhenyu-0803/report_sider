#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class QrCodeNoteElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit QrCodeNoteElement(QWidget *parent = nullptr);
    virtual ~QrCodeNoteElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};