#include "GroupModel.h"
#include "UnitElementModel.h"
#include "FieldElementModel.h"
#include <QJsonArray>

GroupModel::GroupModel(QObject *parent)
    : QObject(parent) {
}

GroupModel::~GroupModel() {
    // 清理元素模型
    qDeleteAll(m_elementModels);
    m_elementModels.clear();
}

void GroupModel::setConfig(const QJsonObject& groupConfig) {
    m_groupConfig = groupConfig;
    m_label = groupConfig["label"].toString();
    m_type = groupConfig["type"].toString();
}

void GroupModel::loadData() {
    // 创建元素模型
    createElementModels();
    
    // 加载所有元素的数据
    for (ElementModel* model : m_elementModels) {
        model->loadData();
    }
}

QString GroupModel::getLabel() const {
    return m_label;
}

QString GroupModel::getType() const {
    return m_type;
}

QList<ElementModel*> GroupModel::getElementModels() const {
    return m_elementModels;
}

void GroupModel::createElementModels() {
    // 清理现有的元素模型
    qDeleteAll(m_elementModels);
    m_elementModels.clear();
    
    // 根据组类型创建不同的元素模型
    if (m_type == "group1" || m_type == "group2") {
        // Unit组
        QJsonArray elementsArray = m_groupConfig["unit_element"].toArray();
        for (const QJsonValue& value : elementsArray) {
            QJsonObject elementObject = value.toObject();
            UnitElementModel* model = new UnitElementModel(elementObject, this);
            m_elementModels.append(model);
        }
    } else {
        // Field组
        QJsonArray fieldsArray = m_groupConfig["fields"].toArray();
        for (const QJsonValue& value : fieldsArray) {
            QJsonObject fieldObject = value.toObject();
            FieldElementModel* model = new FieldElementModel(fieldObject, this);
            m_elementModels.append(model);
        }
    }
}