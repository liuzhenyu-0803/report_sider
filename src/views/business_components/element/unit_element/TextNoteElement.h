#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TextNoteElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit TextNoteElement(QWidget *parent = nullptr);
    virtual ~TextNoteElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;
};