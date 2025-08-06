#pragma once

#include <QObject>
#include <QImage>
#include <QString>

// 包含ImageElementModel头文件
#include "../models/ImageElementModel.h"

class ImageElementViewModel : public QObject {
    Q_OBJECT

public:
    explicit ImageElementViewModel(QObject *parent = nullptr);
    virtual ~ImageElementViewModel();

    QImage getImage() const;
    
signals:
    void signalImageChanged();

protected:
    ImageElementModel *m_imageElementModel;
    QImage m_image;
};