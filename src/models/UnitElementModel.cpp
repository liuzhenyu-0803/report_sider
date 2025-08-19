#include "UnitElementModel.h"
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QBuffer>

UnitElementModel::UnitElementModel(const QJsonObject& elementConfig, QObject *parent)
    : ElementModel(ElementType::Base, parent), m_elementConfig(elementConfig) {
    // 解析配置
    parseConfig();
}

UnitElementModel::~UnitElementModel() = default;

void UnitElementModel::loadData() {
    // 根据配置加载数据
    QString contentType = m_elementConfig["content_type"].toString();
    
    if (contentType == "html") {
        m_type = ElementType::Html;
        m_htmlContent = m_elementConfig["content"].toString();
        data.html = m_htmlContent;
    } else if (contentType == "text") {
        m_type = ElementType::Html;
        // 将文本转换为HTML格式
        QString text = m_elementConfig["content"].toString();
        m_htmlContent = "<pre>" + text + "</pre>";
        data.html = m_htmlContent;
        data.text = text;
    } else if (contentType == "urls") {
        m_type = ElementType::Urls;
        QJsonArray urlsArray = m_elementConfig["content"].toArray();
        for (const QJsonValue& value : urlsArray) {
            m_urls.append(QUrl(value.toString()));
        }
        data.urls = m_urls;
    }
    
    emit signalLoadFinished();
}

QMimeData* UnitElementModel::getMimeData() const {
    QMimeData *mimeData = new QMimeData;
    
    QString contentType = m_elementConfig["content_type"].toString();
    
    if (contentType == "html") {
        QString htmlContent = m_elementConfig["content"].toString();
        mimeData->setHtml(htmlContent);
        mimeData->setText(htmlContent);
    } else if (contentType == "text") {
        QString textContent = m_elementConfig["content"].toString();
        mimeData->setText(textContent);
        mimeData->setHtml("<pre>" + textContent + "</pre>");
    } else if (contentType == "urls") {
        QJsonArray urlsArray = m_elementConfig["content"].toArray();
        QList<QUrl> urls;
        for (const QJsonValue& value : urlsArray) {
            urls.append(QUrl(value.toString()));
        }
        mimeData->setUrls(urls);
    }
    
    return mimeData;
}

void UnitElementModel::parseConfig() {
    // 解析配置并设置UI数据
    data.name = m_elementConfig["label"].toString();
    
    // 如果有图标路径，加载图标
    QString iconPath = m_elementConfig["icon"].toString();
    if (!iconPath.isEmpty()) {
        // 这里可以加载图标文件
        // 暂时使用默认图像
        data.icon = QImage();
    }
}