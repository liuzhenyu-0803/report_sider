#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/common_components/TitleSpinBox.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class LineTemperatureCurveDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit LineTemperatureCurveDraggable(QWidget *parent = nullptr);
    virtual ~LineTemperatureCurveDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    RuleTypeTitleSelector *m_selector = nullptr;
    TitleSpinBox *m_spinBox = nullptr;
};
