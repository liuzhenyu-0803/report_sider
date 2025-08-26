#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcCheckBox.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class ThermalImageElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit ThermalImageElement(QWidget *parent = nullptr);
    virtual ~ThermalImageElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;

    private:
    MicroUI::QcCheckBox *m_checkBox = nullptr;
};
