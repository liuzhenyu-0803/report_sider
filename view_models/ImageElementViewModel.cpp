#include "ImageElementViewModel.h"

ImageElementViewModel::ImageElementViewModel(QObject *parent)
    : QObject(parent) {
    m_imageElementModel = new ImageElementModel(this);

    connect(m_imageElementModel, &ImageElementModel::imageChanged, this, [this]() {
        m_image = m_imageElementModel->getImage();
        emit signalImageChanged();
    });

    m_imageElementModel->loadImagePath("path/to/image.png");
}

ImageElementViewModel::~ImageElementViewModel() = default;

QImage ImageElementViewModel::getImage() const
{
    return m_image;
}
