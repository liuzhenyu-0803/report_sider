#include "HtmlElement.h"
#include <QPainter>
#include <QStyleOption>
#include <QTextDocument>
#include "../../view_models/HtmlElementViewModel.h"

HtmlElement::HtmlElement(HtmlElementViewModel *viewModel, QWidget *parent)
    : Element(viewModel, parent) {
    // 可以在这里设置一些特定于HTML元素的属性
}

HtmlElement::~HtmlElement() = default;

void HtmlElement::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    
    // 先绘制红色背景
    p.setBrush(Qt::red);
    p.drawRect(rect());
    
    // 从ViewModel中获取HTML数据
    HtmlElementViewModel *htmlViewModel = dynamic_cast<HtmlElementViewModel*>(m_viewModel);
    if (htmlViewModel) {
        // 通过ViewModel获取HtmlElementModel，然后获取数据
        Data data = htmlViewModel->getHtmlElementModel()->getData();
        
        // 如果有HTML内容则绘制HTML
        if (!data.html.isEmpty()) {
            // 使用QTextDocument来渲染HTML内容
            QTextDocument doc;
            doc.setHtml(data.html);
            doc.setTextWidth(width() - 10); // 留一些边距
            
            // 在元素中心绘制HTML内容
            p.translate(5, (height() - doc.size().height()) / 2);
            doc.drawContents(&p);
        }
    }
}