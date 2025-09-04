#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/common_components/TitleSpinBox.h"
#include "views/common_components/TitleLineEdit.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TemperatureHistogramDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit TemperatureHistogramDraggable(QWidget *parent = nullptr);
    virtual ~TemperatureHistogramDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    RuleTypeTitleSelector *m_selector = nullptr;
    TitleSpinBox *m_spinBox = nullptr;
    TitleLineEdit *m_lineEdit = nullptr;
};
