#include "UrlsElementViewModel.h"
#include <QMimeData>
#include <QUrl>

UrlsElementViewModel::UrlsElementViewModel(QObject *parent)
    : ElementViewModel(parent) {
    m_urlsElementModel = new UrlsElementModel(this);
    // 设置基类的m_elementModel指针
    m_elementModel = m_urlsElementModel;

    connect(m_urlsElementModel, &UrlsElementModel::signalLoadFinished, this, [this]() {
        Data data = m_urlsElementModel->getData();
        m_urls = data.urls;
    });

    m_urlsElementModel->loadData();
}

UrlsElementViewModel::~UrlsElementViewModel() = default;

UrlsElementModel* UrlsElementViewModel::getUrlsElementModel() const {
    return m_urlsElementModel;
}

QMimeData* UrlsElementViewModel::getMimeData() const {
    QMimeData *mimeData = new QMimeData;
    
    // 获取数据
    Data data = m_urlsElementModel->getData();
    
    // 设置URLs到MimeData - 这是关键功能
    if (!m_urls.isEmpty()) {
        mimeData->setUrls(m_urls);
    }
    
    return mimeData;
}