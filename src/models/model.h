#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QPair>
#include <QStringList>
#include <QJsonObject>

class Model : public QObject
{
    Q_OBJECT

signals:
    void signalThermalImageIndexChanged(int index);

public:
    virtual ~Model();

    static Model *getInstance()
    {
        static Model instance;
        return &instance;
    }

    void setThermalImageIndex(int index);
    int getThermalImageIndex();

    // 读取文本备注模板JSON文件接口
    QList<QPair<QString, QStringList>> getTextRemarkTemplateKeys();

private:
    explicit Model(QObject *parent = nullptr);
    
    // 辅助方法：递归提取JSON对象中的所有key
    void extractKeysFromObject(const QJsonObject &obj, QStringList &keys);

private:
    int m_thermalImageIndex = 0;
};

#endif // MODEL_H