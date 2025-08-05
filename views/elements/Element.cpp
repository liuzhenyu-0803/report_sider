#include "Element.h"
#include <QPainter>
#include <QStyleOption>

Element::Element(QWidget *parent)
    : QWidget(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
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
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}