#include "ElementViewModel.h"
#include "../models/ElementModel.h"

ElementViewModel::ElementViewModel(QObject *parent)
    : QObject(parent), m_elementModel(nullptr) {
}

ElementViewModel::~ElementViewModel() = default;

UIData ElementViewModel::getUIData() const {
    UIData uiData;
    // 直接使用成员变量m_elementModel
    if (m_elementModel) {
        Data data = m_elementModel->getData();
        uiData.icon = data.icon;
        uiData.name = data.name;
    } else {
        // 如果没有ElementModel，返回空的UI数据
        uiData.icon = QImage();
        uiData.name = "";
    }
    return uiData;
}