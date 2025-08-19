#include "ElementModel.h"

ElementModel::ElementModel(ElementType type, QObject *parent)
    : QObject(parent), m_type(type) {
    // 初始化data成员
    data.html = "";
    data.image = QImage();
    data.text = "";
    data.icon = QImage();  // 初始化新字段
    data.name = "";        // 初始化新字段
    
    // 初始化子类特有的成员变量
    m_htmlContent = "";
    m_imagePath = "path/to/image.png";
    
    // 初始化一些示例URLs
    // m_urls.append(QUrl("https://www.example.com"));
    // m_urls.append(QUrl("https://www.google.com"));
    m_urls.append(QUrl("file:///C:/Users/liuzhenyu/Desktop/image1.png"));
    
    // 根据类型初始化特定内容
    switch (m_type) {
    case ElementType::Html: {
        // 初始化HTML内容
        m_htmlContent = "<html><head><meta content=\"text/html; charset=utf-8\" http-equiv=\"content-type\"></head><body><p>paragragh_1</p></body></html>";
        m_htmlContent = "<html><head><meta content=\"text/html; charset=utf-8\" http-equiv=\"content-type\"></head><body><table border='1' style='border-collapse: collapse;'><tr><td><img src=\":/images/test.png\" width=\"100\" height=\"100\" alt=\"image_haha\" /></td><td>cell_2</td></tr><tr><td>cell_3</td><td>cell_4<span style='display: none;'>haha</span></td></tr></table></body></html>";
        // m_htmlContent = "<p>paragragh_2<span style='display: none;'>haha</span></p>";
        // m_htmlContent = "<p >paragragh_2</p>";
        m_htmlContent = R"(<html><head><meta content="text/html; charset=utf-8" http-equiv="content-type"></head><body><img alt="image_haha" style="width:256px;height:256px;image-rendering:pixelated;" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAQAAAAECAIAAAAmkwkpAAAAFklEQVQImWNgYGBg+P///w8GhgEAAEwABc3vXo8AAAAASUVORK5CYII=" /></body></html>)";
        // 新增：将本地图片转为base64并插入img标签
        QImage image(":/images/test.png");
        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, "PNG");
        QString base64 = QString::fromLatin1(ba.toBase64());
        m_htmlContent = QString("<html><head><meta content=\"text/html; charset=utf-8\" http-equiv=\"content-type\"></head><body><img alt=\"from QImage\" style=\"width:256px;height:256px;image-rendering:pixelated;\" src=\"data:image/png;base64,%1\" /></body></html>").arg(base64);

        // 新增：直接使用图片路径作为src
        m_htmlContent = "<html><head><meta content=\"text/html; charset=utf-8\" http-equiv=\"content-type\"></head><body><img alt=\"from file path\" style=\"width:256px;height:256px;image-rendering:pixelated;\" src=\":/images/test.png\" /></body></html>";
        break;
    }
    case ElementType::Image:
        break;
    case ElementType::Urls:
        break;
    default:
        break;
    }
}

ElementModel::~ElementModel() = default;

ElementType ElementModel::getType() const {
    return m_type;
}

Data ElementModel::getData() const {
    return data;
}

UIData ElementModel::getUIData() const {
    UIData uiData;
    // 直接使用data成员变量
    uiData.icon = data.icon;
    uiData.name = data.name;
    return uiData;
}

void ElementModel::loadData() {
    switch (m_type) {
    case ElementType::Html:
        // 设置HTML数据
        data.html = m_htmlContent;
        emit signalLoadFinished();
        break;
    case ElementType::Image:
        // 直接加载图片
        loadImage(":/images/test.png");
        break;
    case ElementType::Urls:
        data.urls = m_urls;
        emit signalLoadFinished();
        break;
    default:
        emit signalLoadFinished();
        break;
    }
}

QMimeData* ElementModel::getMimeData() const {
    QMimeData *mimeData = new QMimeData;
    
    switch (m_type) {
    case ElementType::Html: {
        // 获取数据
        Data data = getData();
        if (!data.html.isEmpty()) {
            // 设置HTML格式的数据
            mimeData->setHtml(data.html);
            
            // 同时设置文本格式的数据
            mimeData->setText(data.html);
        }
        break;
    }
    case ElementType::Image: {
        // 获取数据
        Data data = getData();
        if (!data.image.isNull()) {
            // 设置图像数据到MimeData
            mimeData->setImageData(data.image);
            
            // 同时设置HTML格式的数据，以便在Word中正确显示
            {
                QByteArray htmlData = "<img src=\"data:image/png;base64,";
                QByteArray ba;
                QBuffer buffer(&ba);
                buffer.open(QIODevice::WriteOnly);
                data.image.save(&buffer, "PNG");
                htmlData += ba.toBase64();
                htmlData += "\" />";
                mimeData->setHtml(htmlData);
            }
            
            // 设置文件路径
            if (!m_imagePath.isEmpty()) {
                QList<QUrl> urls;
                urls.append(QUrl::fromLocalFile(m_imagePath));
                mimeData->setUrls(urls);
            }
        }
        break;
    }
    case ElementType::Urls: {
        // 获取数据
        Data data = getData();
        
        // 设置URLs到MimeData - 这是关键功能
        if (!data.urls.isEmpty()) {
            mimeData->setUrls(data.urls);
        }
        break;
    }
    default:
        break;
    }
    
    return mimeData;
}

void ElementModel::setHtmlContent(const QString &html) {
    m_htmlContent = html;
}

void ElementModel::setImagePath(const QString &path) {
    m_imagePath = path;
}

void ElementModel::setUrls(const QList<QUrl> &urls) {
    m_urls = urls;
}

void ElementModel::loadImage(const QString &path) {
    data.image.load(path);
    emit signalLoadFinished();
}