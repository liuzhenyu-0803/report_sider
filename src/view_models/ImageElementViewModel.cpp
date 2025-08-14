#include "ImageElementViewModel.h"
#include <QMimeData>
#include <QBuffer>
#include <QUrl>

ImageElementViewModel::ImageElementViewModel(QObject *parent)
    : ElementViewModel(parent), m_imagePath("path/to/image.png") {
    m_imageElementModel = new ImageElementModel(this);
    // 设置基类的m_elementModel指针
    m_elementModel = m_imageElementModel;

    connect(m_imageElementModel, &ImageElementModel::signalLoadFinished, this, [this]() {
        Data data = m_imageElementModel->getData();
        m_image = data.image;
    });

    m_imageElementModel->loadData();
}

ImageElementViewModel::~ImageElementViewModel() = default;

ImageElementModel* ImageElementViewModel::getImageElementModel() const {
    return m_imageElementModel;
}

QMimeData* ImageElementViewModel::getMimeData() const {
    QMimeData *mimeData = new QMimeData;
    
    // 获取数据
    Data data = m_imageElementModel->getData();
    if (!data.image.isNull()) {
        // 设置图像数据到MimeData
        mimeData->setImageData(data.image);
        
        // 同时设置HTML格式的数据，以便在Word中正确显示
        QByteArray htmlData = "<img src=\"data:image/png;base64,";
        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        data.image.save(&buffer, "PNG");
        htmlData += ba.toBase64();
        htmlData += "\" />";
        mimeData->setHtml(htmlData);
        
        // 设置文件路径
        if (!m_imagePath.isEmpty()) {
            QList<QUrl> urls;
            urls.append(QUrl::fromLocalFile(m_imagePath));
            mimeData->setUrls(urls);
        }
    }
    
    return mimeData;
}
