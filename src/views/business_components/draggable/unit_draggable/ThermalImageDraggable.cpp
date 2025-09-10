#include "ThermalImageDraggable.h"
#include "views/business_components/image_creator/image_creator.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

ThermalImageDraggable::ThermalImageDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/thermal_image.svg");
    setText(tr("HeatmapButton"));

    setIconButtonVisible(true);

    setMoreMenuTitle(tr("HeatmapDisplaysConName"));

    auto contentLayout = getMoreMenuContentLayout();

    m_checkBox = new MicroUI::QcCheckBox();
    m_checkBox->setText(tr("PseudoColorBarName"));
    contentLayout->addWidget(m_checkBox);
}

ThermalImageDraggable::~ThermalImageDraggable()
{

}

void ThermalImageDraggable::mousePressEvent(QMouseEvent *event)
{
    ImageCreator imageCreator;
    imageCreator.setBorderColorParams("#FFD0C6");
    imageCreator.setBackgroundColorParams("#FFF1EE");
    imageCreator.setIconPath(":/images/thermal_image.svg");
    imageCreator.setText(QString("%1-%2").arg(Model::getInstance()->getThermalImageIndex()).arg(tr("HeatmapName")));
    if (m_checkBox->isChecked()) 
    {
        imageCreator.setMetaData(QString("img:rm%1.pal").arg(Model::getInstance()->getThermalImageIndex()));
    } 
    else 
    {
        imageCreator.setMetaData(QString("img:rm%1").arg(Model::getInstance()->getThermalImageIndex()));
    }

    auto imagePath = qApp->applicationDirPath() + "/thermal_image.png";
    imageCreator.createImage(imagePath);
     
    QMimeData *mimeData = new QMimeData();
    auto url = QUrl::fromLocalFile(imagePath);
    mimeData->setUrls({url});
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
