#pragma once

#include <QObject>
#include <QImage>
#include <QString>

struct Data {
    QString html;
    QImage image;
    QString text;
};

class ElementModel : public QObject
{
    Q_OBJECT

public:
    explicit ElementModel(QObject *parent = nullptr);
    virtual ~ElementModel();

    // 纯虚函数，子类必须实现
    virtual void loadData() = 0;
    virtual Data getData() const = 0;

signals:
    // 加载完成信号
    void signalLoadFinished();

protected:
    Data data;
};