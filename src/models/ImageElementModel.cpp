#include "ImageElementModel.h"

ImageElementModel::ImageElementModel(QObject *parent)
    : ElementModel(parent) {
}

ImageElementModel::~ImageElementModel() = default;

Data ImageElementModel::getData() const {
    return data;
}

void ImageElementModel::loadImage(const QString &path) {
    data.image.load(path);
    emit signalLoadFinished();
}

void ImageElementModel::loadData() {
    // 直接加载图片
    loadImage("E:/projects/qt/report_sider/images/test.png");
}