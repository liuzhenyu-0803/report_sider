#include "ElementModel.h"

ElementModel::ElementModel(QObject *parent)
    : QObject(parent) {
    // 初始化data成员
    data.html = "";
    data.image = QImage();
    data.text = "";
    data.icon = QImage();  // 初始化新字段
    data.name = "";        // 初始化新字段
}

ElementModel::~ElementModel() = default;