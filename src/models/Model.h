#pragma once

#include <QObject>
#include <QList>
#include <QJsonObject>
#include "GroupModel.h"

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);
    virtual ~Model();

    // 加载配置文件
    virtual void loadConfig(const QString& filePath) = 0;
    
    // 获取组模型列表
    QList<GroupModel*> getGroupModels() const;

protected:
    QList<GroupModel*> m_groupModels;
    
    // 清理组模型
    void clearGroupModels();
};