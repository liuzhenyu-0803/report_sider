#include "UrlsElement.h"
#include <QPainter>
#include <QStyleOption>
#include <QTextDocument>
#include <QUrl>
#include "../../../view_models/UrlsElementViewModel.h"

UrlsElement::UrlsElement(UrlsElementViewModel *viewModel, QWidget *parent)
    : Element(viewModel, parent) {
    // 可以在这里设置一些特定于URLs元素的属性
}

UrlsElement::~UrlsElement() = default;

void UrlsElement::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    
    // 先绘制蓝色背景，区别于其他元素
    p.setBrush(Qt::blue);
    p.drawRect(rect());
    
    // 从ViewModel中获取URLs数据
    UrlsElementViewModel *urlsViewModel = dynamic_cast<UrlsElementViewModel*>(m_viewModel);
    if (urlsViewModel) {
        // 通过ViewModel获取UrlsElementModel，然后获取数据
        Data data = urlsViewModel->getUrlsElementModel()->getData();
        
        // 如果有文本内容则绘制URLs列表
        if (!data.text.isEmpty()) {
            // 使用QTextDocument来渲染文本内容
            QTextDocument doc;
            doc.setPlainText(data.text);
            doc.setTextWidth(width() - 10); // 留一些边距
            
            // 设置文本颜色为白色，在蓝色背景上更清晰
            QPalette palette;
            palette.setColor(QPalette::Text, Qt::white);
            doc.setDefaultStyleSheet("color: white; font-size: 8px;");
            
            // 在元素中心绘制URLs内容
            p.translate(5, (height() - doc.size().height()) / 2);
            doc.drawContents(&p);
        }
    }
}