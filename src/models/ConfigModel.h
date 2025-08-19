#pragma once

#include "Model.h"
#include <QString>
#include <QJsonDocument>
#include <QFile>
#include <QJsonParseError>

class ConfigModel : public Model
{
    Q_OBJECT

public:
    explicit ConfigModel(QObject *parent = nullptr);
    virtual ~ConfigModel();

    // 重写基类方法
    void loadConfig(const QString& filePath) override;

private:
    // 加载JSON配置文件
    bool loadJsonFile(const QString& filePath, QJsonObject& jsonObject);
    
    // 根据文件名确定组键名
    QString getGroupKey(const QString& filePath) const;
};