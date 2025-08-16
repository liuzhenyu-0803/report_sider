#include "Element.h"
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
#include "../../../view_models/ElementViewModel.h"

Element::Element(ElementViewModel *viewModel, QWidget *parent)
    : QWidget(parent), m_viewModel(viewModel) {
    setAttribute(Qt::WA_StyledBackground, true);
    // 设置固定大小为100x100
    setFixedSize(100, 100);
    // 启用鼠标跟踪
    setMouseTracking(true);
}

Element::~Element() = default;

void Element::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.setBrush(Qt::red); // 设置背景颜色为红色
    p.drawRect(rect()); // 绘制边框
}

void Element::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragStartPos = event->pos();
        
        // 将MimeData设置到剪切板中
        QMimeData *mimeData = m_viewModel->getMimeData();
        QMimeData *clipboardMimeData = new QMimeData();
        
        // 复制所有格式的数据到剪切板
        foreach(const QString &format, mimeData->formats()) {
            clipboardMimeData->setData(format, mimeData->data(format));
        }
        
        QApplication::clipboard()->setMimeData(clipboardMimeData);
    }
    QWidget::mousePressEvent(event);
}

void Element::mouseMoveEvent(QMouseEvent *event) {
    if (!(event->buttons() & Qt::LeftButton)) {
        QWidget::mouseMoveEvent(event);
        return;
    }
    
    if ((event->pos() - m_dragStartPos).manhattanLength() < QApplication::startDragDistance()) {
        QWidget::mouseMoveEvent(event);
        return;
    }
    
    startDrag();
    QWidget::mouseMoveEvent(event);
}

void Element::startDrag() {
    QDrag *drag = new QDrag(this);
    
    // 通过ViewModel获取MimeData
    QMimeData *mimeData = m_viewModel->getMimeData();
    
    drag->setMimeData(mimeData);
    
    // 设置拖拽 pixmap
    QPixmap pixmap = grab();
    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(pixmap.width() / 2, pixmap.height() / 2));
    
    drag->exec(Qt::CopyAction | Qt::MoveAction);
}

void Element::enterEvent(QEvent *event) {
    setCursor(Qt::PointingHandCursor);
    QWidget::enterEvent(event);
}

void Element::leaveEvent(QEvent *event) {
    setCursor(Qt::ArrowCursor);
    QWidget::leaveEvent(event);
}