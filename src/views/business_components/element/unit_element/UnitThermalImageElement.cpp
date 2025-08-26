#include "UnitThermalImageElement.h"
#include <QMimeData>
#include <QIcon>

UnitThermalImageElement::UnitThermalImageElement(QWidget *parent)
    : UnitElementFrame(parent)
{
    auto contentLayout = getMoreMenuContentLayout();

    m_checkBox = new MicroUI::QcCheckBox();
    m_checkBox->setText("pseudo_color");
    contentLayout->addWidget(m_checkBox);
}

UnitThermalImageElement::~UnitThermalImageElement()
{
}

QString UnitThermalImageElement::getIcon() const
{
    // 返回一个简单的图标，实际项目中可能需要加载真实的图标资源
    return ":/images/close.svg";
}

QString UnitThermalImageElement::getText() const
{
    return "Thermal Image";
}

QMimeData* UnitThermalImageElement::getMimeData() const
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
