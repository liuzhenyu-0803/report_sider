#include "TemperatureHistogramDraggable.h"
#include <QMimeData>
#include <QBoxLayout>
#include <QIcon>

TemperatureHistogramDraggable::TemperatureHistogramDraggable(QWidget *parent)
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

TemperatureHistogramDraggable::~TemperatureHistogramDraggable()
{

}

QString TemperatureHistogramDraggable::getIcon() const
{
    return ":/images/temperature_histogram.svg";
}

QString TemperatureHistogramDraggable::getText() const
{
    return "Temperature Histogram";
}

QMimeData* TemperatureHistogramDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TemperatureHistogramDraggable");
    mimeData->setData("application/x-temperaturehistogram", QByteArray());
    
    return mimeData;
}
