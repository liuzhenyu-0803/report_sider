#include "LineTemperatureCurveDraggable.h"
#include <QMimeData>
#include <QIcon>

LineTemperatureCurveDraggable::LineTemperatureCurveDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIconButtonVisible(true);

    auto contentLayout = getMoreMenuContentLayout();

    auto innerFrame = new QFrame();
    innerFrame->setFixedWidth(216);
    auto innerLayout = new QHBoxLayout();
    innerLayout->setContentsMargins(0, 0, 0, 0);
    innerLayout->setSpacing(8);
    innerFrame->setLayout(innerLayout);

    m_selector = new MicroUI::QcSelector();
    m_selector->setFixedHeight(28);
    m_selector->addItem("Auto");
    m_selector->addItem("Manual");
    innerLayout->addWidget(m_selector);

    m_spinBox = new MicroUI::QcSpinBox();
    m_spinBox->setFixedHeight(28);
    m_spinBox->setRange(0, 100);
    m_spinBox->setValue(50);
    innerLayout->addWidget(m_spinBox);

    contentLayout->addWidget(innerFrame);
}

LineTemperatureCurveDraggable::~LineTemperatureCurveDraggable()
{
}

QString LineTemperatureCurveDraggable::getIcon() const
{
    return ":/images/line_temperature_curve.svg";
}

QString LineTemperatureCurveDraggable::getText() const
{
    return "Line Temperature Curve";
}

QMimeData* LineTemperatureCurveDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("LineTemperatureCurveDraggable");
    mimeData->setData("application/x-linetemperaturecurve", QByteArray());
    
    return mimeData;
}
