#include "VisibleLightDraggable.h"
#include "views/business_components/image_creator/image_creator.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

VisibleLightDraggable::VisibleLightDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/visible_light.svg");
    setText(tr("VisiblelightButton"));

    setIconButtonVisible(true);

    setMoreMenuTitle(tr("VisibleLightTypeName"));

    auto contentLayout = getMoreMenuContentLayout();

    contentLayout->setSpacing(5);

    m_radio1Button = new MicroUI::QcRadioButton();
    m_radio1Button->setText(tr("AlignVisibleLightName"));
    contentLayout->addWidget(m_radio1Button);

    m_radio2Button = new MicroUI::QcRadioButton();
    m_radio2Button->setText(tr("PanoramicVisibleLiName"));
    contentLayout->addWidget(m_radio2Button);

    m_radio1Button->setChecked(true);
}

VisibleLightDraggable::~VisibleLightDraggable()
{

}

void VisibleLightDraggable::mousePressEvent(QMouseEvent *event)
{
    ImageCreator imageCreator;
    imageCreator.setBorderColorParams("#B5D4FF");
    imageCreator.setBackgroundColorParams("#E7F1FF");
    imageCreator.setIconPath(":/images/visible_light.svg");
    if (m_radio1Button->isChecked()) 
    {
        imageCreator.setText(QString("%1-%2").arg(Model::getInstance()->getThermalImageIndex()).arg(tr("VisibleLightName")));
        imageCreator.setMetaData(QString("img:rm%1.val").arg(Model::getInstance()->getThermalImageIndex()));
    } 
    else 
    {
        imageCreator.setText(QString("%1-%2").arg(Model::getInstance()->getThermalImageIndex()).arg(tr("VisibleLightName")));
        imageCreator.setMetaData(QString("img:rm%1.vfw").arg(Model::getInstance()->getThermalImageIndex()));
    }

    auto imagePath = qApp->applicationDirPath() + "/visible_light.png";
    imageCreator.createImage(imagePath);
     
    QMimeData *mimeData = new QMimeData();
    auto url = QUrl::fromLocalFile(imagePath);
    mimeData->setUrls({url});
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
