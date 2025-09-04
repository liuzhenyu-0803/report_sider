#include "TemperatureHistogramDraggable.h"
#include "views/business_components/image_creator/image_creator.h"
#include "views/business_components/title_combine_widget/RuleSequenceTitleSpinBox.h"
#include "models/model.h"
#include <QMimeData>
#include <QBoxLayout>
#include <QIcon>
#include <QUrl>
#include <QIntValidator>

TemperatureHistogramDraggable::TemperatureHistogramDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/temperature_histogram.svg");
    setText("Temperature Histogram");

    setIconButtonVisible(true);

    setMoreMenuTitle(tr("select rule"));

    getMoreMenu()->setFixedWidth(232);

    auto contentLayout = getMoreMenuContentLayout();
    contentLayout->setContentsMargins(8, 0, 8, 8);
    contentLayout->setSpacing(8);

    auto hlayout = new QHBoxLayout();
    hlayout->setContentsMargins(0, 0, 0, 0);
    hlayout->setSpacing(6);

    m_selector = new RuleTypeTitleSelector();
    hlayout->addWidget(m_selector);

    m_spinBox = new RuleSequenceTitleSpinBox();
    hlayout->addWidget(m_spinBox);

    qobject_cast<QBoxLayout *>(contentLayout)->addLayout(hlayout);

    m_lineEdit = new TitleLineEdit();
    m_lineEdit->setTitle(tr("group 2-64"));
    m_lineEdit->setText("2");
    auto validator = new QIntValidator(2, 64, this);
    m_lineEdit->setValidator(validator);
    contentLayout->addWidget(m_lineEdit);
}

TemperatureHistogramDraggable::~TemperatureHistogramDraggable()
{

}

void TemperatureHistogramDraggable::mousePressEvent(QMouseEvent *event)
{
    ImageCreator imageCreator;
    imageCreator.setBackgroundColorParams("#BFD990");
    imageCreator.setIconPath(":/images/temperature_histogram.svg");
    imageCreator.setText(QString("%1-%2").arg(Model::getInstance()->getThermalImageIndex()).arg(tr("histogram")));
    if (m_selector->getCurrentType() == RuleTypeTitleSelector::RuleType::G) 
    {
         imageCreator.setMetaData(QString("ct:rm%1.his.%2.gp%3").arg(Model::getInstance()->getThermalImageIndex()).arg(m_selector->getCurrentTypeText()).arg(m_lineEdit->getText()));
    }
    else 
    {
         imageCreator.setMetaData(QString("ct:rm%1.his.%2%3.gp%4").arg(Model::getInstance()->getThermalImageIndex()).arg(m_selector->getCurrentTypeText()).arg(m_spinBox->value()).arg(m_lineEdit->getText()));
    }

    auto imagePath = qApp->applicationDirPath() + "/temperature_histogram.png";
    imageCreator.createImage(imagePath);
     
    QMimeData *mimeData = new QMimeData();
    auto url = QUrl::fromLocalFile(imagePath);
    mimeData->setUrls({url});
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
