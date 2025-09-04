#ifndef MODEL_H
#define MODEL_H

#include <QObject>

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

private:
    explicit Model(QObject *parent = nullptr);

private:
    int m_thermalImageIndex = 0;
};

#endif // MODEL_H