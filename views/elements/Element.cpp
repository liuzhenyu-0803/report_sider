#include "Element.h"
#include <QPainter>
#include <QStyleOption>

Element::Element(ImageElementViewModel *viewModel, QWidget *parent)
    : QWidget(parent), m_viewModel(viewModel) {
    setAttribute(Qt::WA_StyledBackground, true);
    // 设置固定大小为100x100
    setFixedSize(100, 100);
}

Element::~Element() = default;

void Element::setHtml(const QString &html) {
    m_html = html;
    update();
}

void Element::setImageData(const QVariant &image) {
    m_imageData = image;
    update();
}

void Element::setText(const QString &text) {
    m_text = text;
    update();
}

void Element::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.setBrush(Qt::red); // 设置背景颜色为红色
    p.drawRect(rect()); // 绘制边框
}