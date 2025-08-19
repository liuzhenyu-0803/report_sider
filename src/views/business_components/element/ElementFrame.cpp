#include "ElementFrame.h"
#include <QPainter>
#include <QStyleOption>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QApplication>
#include <QBitmap>
#include <QBuffer>
#include <QUrl>
#include <QClipboard>

ElementFrame::ElementFrame(QWidget *parent)
    : QWidget(parent) {
    setAttribute(Qt::WA_StyledBackground, true);
    // 设置固定大小为100x100
    setFixedSize(100, 100);
    // 启用鼠标跟踪
    setMouseTracking(true);
}

ElementFrame::~ElementFrame() = default;

void ElementFrame::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    
    // 绘制简单背景
    p.setBrush(Qt::lightGray);
    p.drawRect(rect()); // 绘制边框
}


void ElementFrame::enterEvent(QEvent *event) {
    setCursor(Qt::PointingHandCursor);
    QWidget::enterEvent(event);
}

void ElementFrame::leaveEvent(QEvent *event) {
    setCursor(Qt::ArrowCursor);
    QWidget::leaveEvent(event);
}

void ElementFrame::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
}

void ElementFrame::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
}

void ElementFrame::startDrag() {
    // TODO: 实现拖拽功能
}

void ElementFrame::paintHtmlElement(QPainter &p) {
    // TODO: 实现HTML元素绘制
}

void ElementFrame::paintImageElement(QPainter &p) {
    // TODO: 实现图像元素绘制
}

void ElementFrame::paintUrlsElement(QPainter &p) {
    // TODO: 实现URL元素绘制
}