#include "TemperatureHistogramElement.h"
#include <QMimeData>
#include <QBoxLayout>
#include <QIcon>

TemperatureHistogramElement::TemperatureHistogramElement(QWidget *parent)
    : UnitElementFrame(parent)
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

TemperatureHistogramElement::~TemperatureHistogramElement()
{

}

QString TemperatureHistogramElement::getIcon() const
{
    return ":/images/temperature_histogram.svg";
}

QString TemperatureHistogramElement::getText() const
{
    return "Temperature Histogram";
}

QMimeData* TemperatureHistogramElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TemperatureHistogramElement");
    mimeData->setData("application/x-temperaturehistogram", QByteArray());
    
    return mimeData;
}