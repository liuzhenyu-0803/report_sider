#include "ElementModel.h"

ElementModel::ElementModel(QObject *parent)
    : QObject(parent) {
    // 初始化data成员
    data.html = "";
    data.image = QImage();
    data.text = "";
}

ElementModel::~ElementModel() = default;