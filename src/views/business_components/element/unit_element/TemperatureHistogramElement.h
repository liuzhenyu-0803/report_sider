#pragma once

#include "../UnitElementFrame.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcSelector.h"
#include "QcDoubleSpinBox.h"
#include "views/common_components/SpinBox.h"
#include <QIcon>
#include <QMimeData>
#include <QString>

class TemperatureHistogramElement : public UnitElementFrame
{
    Q_OBJECT

public:
    explicit TemperatureHistogramElement(QWidget *parent = nullptr);
    virtual ~TemperatureHistogramElement();

protected:
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;

private:
    MicroUI::QcSelector *m_selector = nullptr;
    MicroUI::QcSpinBox *m_spinBox = nullptr;
};