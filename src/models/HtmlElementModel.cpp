#include "HtmlElementModel.h"
#include <QImage>
#include <QBuffer>
#include <QByteArray>

HtmlElementModel::HtmlElementModel(QObject *parent)
    : ElementModel(parent) {
    // 初始化HTML内容
    m_htmlContent = "<html><head><meta content=\"text/html; charset=utf-8\" http-equiv=\"content-type\"></head><body><p>paragragh_1</p></body></html>";
    m_htmlContent = "<html><head><meta content=\"text/html; charset=utf-8\" http-equiv=\"content-type\"></head><body><table border='1' style='border-collapse: collapse;'><tr><td><img src=\"E:/projects/qt/report_sider/images/test.png\" width=\"100\" height=\"100\" alt=\"image_haha\" /></td><td>cell_2</td></tr><tr><td>cell_3</td><td>cell_4<span style='display: none;'>haha</span></td></tr></table></body></html>";
    // m_htmlContent = "<p>paragragh_2<span style='display: none;'>haha</span></p>";
    // m_htmlContent = "<p >paragragh_2</p>";
    m_htmlContent = R"(<html><head><meta content="text/html; charset=utf-8" http-equiv="content-type"></head><body><img alt="image_haha" style="width:256px;height:256px;image-rendering:pixelated;" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAQAAAAECAIAAAAmkwkpAAAAFklEQVQImWNgYGBg+P///w8GhgEAAEwABc3vXo8AAAAASUVORK5CYII=" /></body></html>)";
    // 新增：将本地图片转为base64并插入img标签
    QImage image("E:/projects/qt/report_sider/images/test.png");
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
    QString base64 = QString::fromLatin1(ba.toBase64());
    m_htmlContent = QString("<html><head><meta content=\"text/html; charset=utf-8\" http-equiv=\"content-type\"></head><body><img alt=\"from QImage\" style=\"width:256px;height:256px;image-rendering:pixelated;\" src=\"data:image/png;base64,%1\" /></body></html>").arg(base64);

    // 新增：直接使用图片路径作为src
    m_htmlContent = "<html><head><meta content=\"text/html; charset=utf-8\" http-equiv=\"content-type\"></head><body><img alt=\"from file path\" style=\"width:256px;height:256px;image-rendering:pixelated;\" src=\"E:/projects/qt/report_sider/images/test.png\" /></body></html>";
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