#include "HtmlElementModel.h"

HtmlElementModel::HtmlElementModel(QObject *parent)
    : ElementModel(parent) {
    // 初始化HTML内容
    m_htmlContent = "<p>paragragh_1</p>";
    m_htmlContent = "<table border='1' style='border-collapse: collapse;'><tr><td>cell_1</td><td>cell_2</td></tr><tr><td>cell_3</td><td>cell_4</td></tr></table>";
}

HtmlElementModel::~HtmlElementModel() = default;

Data HtmlElementModel::getData() const {
    return data;
}

void HtmlElementModel::loadData() {
    // 设置HTML数据
    data.html = m_htmlContent;
    emit signalLoadFinished();
}