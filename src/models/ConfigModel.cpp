#include "ConfigModel.h"
#include <QJsonArray>
#include <QFileInfo>
#include <QDebug>

ConfigModel::ConfigModel(QObject *parent)
    : Model(parent) {
}

ConfigModel::~ConfigModel() = default;

void ConfigModel::loadConfig(const QString& filePath) {
    // 清理现有的组模型
    clearGroupModels();
    
    // 加载JSON配置文件
    QJsonObject rootObject;
    if (!loadJsonFile(filePath, rootObject)) {
        qDebug() << "Failed to load config file:" << filePath;
        return;
    }
    
    // 根据文件名确定组键名
    QString groupKey = getGroupKey(filePath);
    
    // 解析组配置
    QJsonArray groupsArray = rootObject[groupKey].toArray();
    for (const QJsonValue& value : groupsArray) {
        QJsonObject groupObject = value.toObject();
        GroupModel* groupModel = new GroupModel(this);
        groupModel->setConfig(groupObject);
        groupModel->loadData();
        m_groupModels.append(groupModel);
    }
}

bool ConfigModel::loadJsonFile(const QString& filePath, QJsonObject& jsonObject) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file:" << filePath;
        return false;
    }
    
    QByteArray jsonData = file.readAll();
    file.close();
    
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &error);
    if (error.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON file:" << filePath << "Error:" << error.errorString();
        return false;
    }
    
    if (!doc.isObject()) {
        qDebug() << "JSON document is not an object:" << filePath;
        return false;
    }
    
    jsonObject = doc.object();
    return true;
}

QString ConfigModel::getGroupKey(const QString& filePath) const {
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();
    
    if (fileName == "unit_config.json") {
        return "unit_groups";
    } else if (fileName == "field_config.json") {
        return "field_groups";
    }
    
    // 默认返回unit_groups
    return "unit_groups";
}