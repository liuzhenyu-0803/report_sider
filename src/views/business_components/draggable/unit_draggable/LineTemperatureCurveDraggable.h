#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "QcSelector.h"
#include "QcDoubleSpinBox.h"
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
    QString getIcon() const override;
    QString getText() const override;
    QMimeData* getMimeData() const override;

private:
    MicroUI::QcSelector *m_selector = nullptr;
    MicroUI::QcSpinBox *m_spinBox = nullptr;
};
