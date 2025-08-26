#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcRadioButton.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class VisibleLightElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit VisibleLightElement(QWidget *parent = nullptr);
    virtual ~VisibleLightElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;

private:
    MicroUI::QcRadioButton *m_radio1Button = nullptr;
    MicroUI::QcRadioButton *m_radio2Button = nullptr;
};