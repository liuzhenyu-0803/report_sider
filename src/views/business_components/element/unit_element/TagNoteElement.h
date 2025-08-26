#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcRadioButton.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TagNoteElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit TagNoteElement(QWidget *parent = nullptr);
    virtual ~TagNoteElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;

private:
    MicroUI::QcRadioButton *m_radio1Button = nullptr;
    MicroUI::QcRadioButton *m_radio2Button = nullptr;
};