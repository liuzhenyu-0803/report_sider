#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcRadioButton.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class VisibleLightDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit VisibleLightDraggable(QWidget *parent = nullptr);
    virtual ~VisibleLightDraggable();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;

private:
    MicroUI::QcRadioButton *m_radio1Button = nullptr;
    MicroUI::QcRadioButton *m_radio2Button = nullptr;
};
