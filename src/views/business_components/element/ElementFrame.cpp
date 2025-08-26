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
#include <QTimer>

ElementFrame::ElementFrame(QWidget *parent)
    : QWidget(parent) {
    // setAttribute(Qt::WA_StyledBackground, true);
    // 设置固定大小为100x100
    setFixedSize(104, 64);
    // 启用鼠标跟踪
    setMouseTracking(true);

    QTimer::singleShot(0, this, &ElementFrame::loadData);
}

ElementFrame::~ElementFrame() = default;

void ElementFrame::enterEvent(QEvent *event) {
    setCursor(Qt::PointingHandCursor);
    update();
    QWidget::enterEvent(event);
}

void ElementFrame::leaveEvent(QEvent *event) {
    setCursor(Qt::ArrowCursor);
    update();
    QWidget::leaveEvent(event);
}

void ElementFrame::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragStartPos = event->pos();
    }
    QWidget::mousePressEvent(event);
}

void ElementFrame::mouseMoveEvent(QMouseEvent *event) {
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

void ElementFrame::startDrag() {
    // 创建拖拽对象
    QDrag *drag = new QDrag(this);
    
    // 获取子类提供的 MimeData
    QMimeData *mimeData = getMimeData();
    if (!mimeData) {
        delete drag;
        return;
    }
    
    drag->setMimeData(mimeData);
    
    // 创建拖拽时的预览图像
    QPixmap dragPixmap(size());
    dragPixmap.fill(Qt::transparent);
    
    QPainter painter(&dragPixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setOpacity(0.8);
    render(&painter);
    painter.end();
    
    drag->setPixmap(dragPixmap);
    drag->setHotSpot(QPoint(dragPixmap.width() / 2, dragPixmap.height() / 2));
    
    // 执行拖拽操作
    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    Q_UNUSED(dropAction)
}