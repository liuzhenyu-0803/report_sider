#include "ThermalImageElement.h"
#include <QMimeData>
#include <QIcon>

ThermalImageElement::ThermalImageElement(QWidget *parent)
    : UnitElementFrame(parent)
{
    setIconButtonVisible(true);

    auto contentLayout = getMoreMenuContentLayout();

    m_checkBox = new MicroUI::QcCheckBox();
    m_checkBox->setText("pseudo_color");
    contentLayout->addWidget(m_checkBox);
}

ThermalImageElement::~ThermalImageElement()
{

}

QString ThermalImageElement::getIcon() const
{
    // 返回一个简单的图标，实际项目中可能需要加载真实的图标资源
    return ":/images/thermal_image.svg";
}

QString ThermalImageElement::getText() const
{
    return "Thermal Image";
}

QMimeData* ThermalImageElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    // 设置热成像元素的 MIME 数据
    mimeData->setText("UnitThermalImageElement");
    mimeData->setData("application/x-unitthermalimage", QByteArray());
    
    // 可以添加图像数据
    // QPixmap image = getImage();
    // if (!image.isNull()) {
    //     mimeData->setImageData(image);
    // }
    
    return mimeData;
}
