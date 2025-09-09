#include "model.h"
#include <QDir>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

Model::Model(QObject *parent)
    : QObject(parent)
{
}

Model::~Model()
{
}

void Model::setThermalImageIndex(int index)
{
    m_thermalImageIndex = index;
    emit signalThermalImageIndexChanged(index);
}

int Model::getThermalImageIndex()
{
    return m_thermalImageIndex;
}

QList<QPair<QString, QStringList>> Model::getTextRemarkTemplateKeys()
{
    QList<QPair<QString, QStringList>> result;
    QString templateDir = "C:/Users/Public/Editor/TextRemarkTemplate";
    
    QDir dir(templateDir);
    if (!dir.exists()) {
        qDebug() << "Template directory does not exist:" << templateDir;
        return result;
    }
    
    // 设置过滤器，只获取JSON文件
    QStringList nameFilters;
    nameFilters << "*.json";
    dir.setNameFilters(nameFilters);
    
    QFileInfoList fileList = dir.entryInfoList(QDir::Files);
    
    for (const QFileInfo &fileInfo : fileList) {
        QString fileName = fileInfo.baseName(); // 不包含扩展名的文件名
        QStringList fieldKeys;
        
        QFile file(fileInfo.absoluteFilePath());
        if (file.open(QIODevice::ReadOnly)) {
            QByteArray data = file.readAll();
            file.close();
            
            QJsonParseError parseError;
            QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
            
            if (parseError.error == QJsonParseError::NoError && doc.isObject()) {
                QJsonObject obj = doc.object();
                
                // 查找Fields数组
                if (obj.contains("Fields") && obj["Fields"].isArray()) {
                    QJsonArray fieldsArray = obj["Fields"].toArray();
                    
                    // 遍历Fields数组，提取每个Field对象中的Key值
                    for (const QJsonValue &fieldValue : fieldsArray) {
                        if (fieldValue.isObject()) {
                            QJsonObject fieldObj = fieldValue.toObject();
                            if (fieldObj.contains("Key") && fieldObj["Key"].isString()) {
                                QString keyValue = fieldObj["Key"].toString();
                                if (!fieldKeys.contains(keyValue)) {
                                    fieldKeys.append(keyValue);
                                }
                            }
                        }
                    }
                }
            } else {
                qDebug() << "Failed to parse JSON file:" << fileInfo.absoluteFilePath()
                         << "Error:" << parseError.errorString();
            }
        } else {
            qDebug() << "Failed to open file:" << fileInfo.absoluteFilePath();
        }
        
        result.append(qMakePair(fileName, fieldKeys));
    }
    
    return result;
}

void Model::extractKeysFromObject(const QJsonObject &obj, QStringList &keys)
{
    // 这个方法现在不再需要，但保留以避免编译错误
    Q_UNUSED(obj);
    Q_UNUSED(keys);
}
