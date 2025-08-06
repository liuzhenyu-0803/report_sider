#include "HtmlElementViewModel.h"
#include <QMimeData>
#include <QBuffer>
#include <QUrl>

HtmlElementViewModel::HtmlElementViewModel(QObject *parent)
    : ElementViewModel(parent), m_htmlContent("<p>这是一个HTML元素示例</p>") {
    m_htmlElementModel = new HtmlElementModel(this);

    connect(m_htmlElementModel, &HtmlElementModel::signalLoadFinished, this, [this]() {
        Data data = m_htmlElementModel->getData();
        m_htmlContent = data.html;
    });

    m_htmlElementModel->loadData();
}

HtmlElementViewModel::~HtmlElementViewModel() = default;

HtmlElementModel* HtmlElementViewModel::getHtmlElementModel() const {
    return m_htmlElementModel;
}

QMimeData* HtmlElementViewModel::getMimeData() const {
    QMimeData *mimeData = new QMimeData;
    
    // 获取数据
    Data data = m_htmlElementModel->getData();
    if (!data.html.isEmpty()) {
        // 设置HTML格式的数据
        mimeData->setHtml(data.html);
        
        // 同时设置文本格式的数据
        mimeData->setText(data.html);
    }
    
    return mimeData;
}