#include "ImageInfoDraggable.h"
#include "models/model.h"
#include <QIcon>
#include <QMimeData>

ImageInfoDraggable::ImageInfoDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/image_info.svg");
    setText(tr("ImageInformationButton"));

    setIconButtonVisible(true);

    setMoreMenuTitle(tr("PictureName"));

    auto contentLayout = getMoreMenuContentLayout();

    m_checkBox = new MicroUI::QcCheckBox();
    m_checkBox->setText(tr("DisplayFileExtensiName"));
    contentLayout->addWidget(m_checkBox);
}

ImageInfoDraggable::~ImageInfoDraggable()
{
}

void ImageInfoDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent(":/html/image_property.html").arg(Model::getInstance()->getThermalImageIndex()).arg(m_checkBox->isChecked() ? ".ext" : ""));
    setMimeData(mimeData);
}
