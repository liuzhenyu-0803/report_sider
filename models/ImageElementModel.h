#pragma once

#include <QObject>
#include <QImage>
#include <QString>

class ImageElementModel : public QObject
{
    Q_OBJECT

public:
    explicit ImageElementModel(QObject *parent = nullptr);
    virtual ~ImageElementModel();

    // 获取图像
    virtual QImage getImage() const;
    
    // 加载图像
    virtual void loadImagePath(const QString &path);
    
signals:
    // 图像变化信号
    void imageChanged();

protected:
    void loadImage(const QString &path);

protected:
    QImage m_image;
};