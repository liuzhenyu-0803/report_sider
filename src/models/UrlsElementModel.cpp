#include "UrlsElementModel.h"
#include <QUrl>

UrlsElementModel::UrlsElementModel(QObject *parent)
    : ElementModel(parent) {
    // 初始化一些示例URLs
    // m_urls.append(QUrl("https://www.example.com"));
    // m_urls.append(QUrl("https://www.google.com"));
    m_urls.append(QUrl("file:///C:/Users/liuzhenyu/Desktop/image1.png"));
}

UrlsElementModel::~UrlsElementModel() = default;

Data UrlsElementModel::getData() const {
    return data;
}

void UrlsElementModel::loadData() {
    data.urls = m_urls;
    emit signalLoadFinished();
}