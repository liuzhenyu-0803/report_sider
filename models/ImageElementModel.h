#pragma once

#include "ElementModel.h"
#include <QImage>
#include <QString>

class ImageElementModel : public ElementModel
{
    Q_OBJECT

public:
    explicit ImageElementModel(QObject *parent = nullptr);
    virtual ~ImageElementModel();

    // 实现基类的纯虚函数
    virtual void loadData() override;
    virtual Data getData() const override;

signals:
    // 加载完成信号
    void signalLoadFinished();

protected:
    void loadImage(const QString &path);
};