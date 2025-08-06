#include "ImageElementModel.h"

ImageElementModel::ImageElementModel(QObject *parent)
    : QObject(parent) {
}

ImageElementModel::~ImageElementModel() = default;

QImage ImageElementModel::getImage() const {
    return m_image;
}

void ImageElementModel::loadImage(const QString &path) {
    m_image.load(path);
    emit imageChanged();
}

void ImageElementModel::loadImagePath(const QString &path) {
    loadImage(path);
}