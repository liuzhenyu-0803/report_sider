#pragma once

#include "ElementViewModel.h"
#include <QImage>
#include <QString>

// 包含ImageElementModel头文件
#include "../models/ImageElementModel.h"

class ImageElementViewModel : public ElementViewModel {
    Q_OBJECT

public:
    explicit ImageElementViewModel(QObject *parent = nullptr);
    virtual ~ImageElementViewModel();

    // 实现基类的纯虚函数
    virtual QMimeData* getMimeData() const override;
    
    // 添加公共方法获取ImageElementModel实例
    ImageElementModel* getImageElementModel() const;

protected:
    ImageElementModel *m_imageElementModel;
    QImage m_image;
    QString m_imagePath;
};