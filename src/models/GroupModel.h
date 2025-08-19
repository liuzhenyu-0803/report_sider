#pragma once

#include <QObject>
#include <QList>
#include <QJsonObject>
#include "ElementModel.h"

class GroupModel : public QObject
{
    Q_OBJECT

public:
    explicit GroupModel(QObject *parent = nullptr);
    virtual ~GroupModel();

    // 设置组配置
    void setConfig(const QJsonObject& groupConfig);
    
    // 加载组数据
    void loadData();
    
    // 获取组标签
    QString getLabel() const;
    
    // 获取组类型
    QString getType() const;
    
    // 获取元素模型列表
    QList<ElementModel*> getElementModels() const;

private:
    QString m_label;
    QString m_type;
    QList<ElementModel*> m_elementModels;
    QJsonObject m_groupConfig;
    
    // 创建元素模型
    void createElementModels();
};