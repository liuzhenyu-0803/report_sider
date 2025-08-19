#include "FieldElementModel.h"
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QBuffer>

FieldElementModel::FieldElementModel(const QJsonObject& fieldConfig, QObject *parent)
    : ElementModel(ElementType::Base, parent), m_fieldConfig(fieldConfig) {
    // 解析配置
    parseConfig();
}

FieldElementModel::~FieldElementModel() = default;

void FieldElementModel::loadData() {
    // 根据字段配置加载数据
    QString fieldType = m_fieldConfig["type"].toString();
    
    if (fieldType == "text") {
        m_type = ElementType::Html;
        QString label = m_fieldConfig["label"].toString();
        QString value = m_fieldConfig["value"].toString();
        m_htmlContent = "<p><strong>" + label + ":</strong> " + value + "</p>";
        data.html = m_htmlContent;
        data.text = label + ": " + value;
    } else if (fieldType == "selector") {
        m_type = ElementType::Html;
        QString label = m_fieldConfig["label"].toString();
        QString value = m_fieldConfig["value"].toString();
        m_htmlContent = "<p><strong>" + label + ":</strong> " + value + "</p>";
        data.html = m_htmlContent;
        data.text = label + ": " + value;
    } else if (fieldType == "spin") {
        m_type = ElementType::Html;
        QString label = m_fieldConfig["label"].toString();
        QString value = m_fieldConfig["value"].toString();
        m_htmlContent = "<p><strong>" + label + ":</strong> " + value + "</p>";
        data.html = m_htmlContent;
        data.text = label + ": " + value;
    }
    
    emit signalLoadFinished();
}

QMimeData* FieldElementModel::getMimeData() const {
    QMimeData *mimeData = new QMimeData;
    
    QString fieldType = m_fieldConfig["type"].toString();
    QString label = m_fieldConfig["label"].toString();
    QString value = m_fieldConfig["value"].toString();
    QString textContent = label + ": " + value;
    
    if (fieldType == "text" || fieldType == "selector" || fieldType == "spin") {
        QString htmlContent = "<p><strong>" + label + ":</strong> " + value + "</p>";
        mimeData->setHtml(htmlContent);
        mimeData->setText(textContent);
    }
    
    return mimeData;
}

void FieldElementModel::parseConfig() {
    // 解析配置并设置UI数据
    data.name = m_fieldConfig["label"].toString();
    
    // 设置默认图标
    data.icon = QImage();
}