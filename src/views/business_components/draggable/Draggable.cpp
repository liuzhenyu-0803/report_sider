#include "Draggable.h"
#include <QPainter>
#include <QStyleOption>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include "QcApplication.h"
#include <QBitmap>
#include <QBuffer>
#include <QUrl>
#include <QClipboard>
#include <QTimer>

Draggable::Draggable(QWidget *parent)
    : QWidget(parent) 
{
    // PostTaskToMainThread(this, [this] {
    //     loadData();
    // });
}

Draggable::~Draggable() 
{
    if (m_customMimeData) 
    {
        delete m_customMimeData;
        m_customMimeData = nullptr;
    }
}

void Draggable::enterEvent(QEvent *event) 
{
    setCursor(Qt::PointingHandCursor);
    update();
    QWidget::enterEvent(event);
}

void Draggable::leaveEvent(QEvent *event) 
{
    setCursor(Qt::ArrowCursor);
    update();
    QWidget::leaveEvent(event);
}

void Draggable::mousePressEvent(QMouseEvent *event) 
{
    if (event->button() == Qt::LeftButton) 
    {
        m_dragStartPos = event->pos();
    }
    QWidget::mousePressEvent(event);
}

void Draggable::mouseMoveEvent(QMouseEvent *event) 
{
    if (!(event->buttons() & Qt::LeftButton)) 
    {
        QWidget::mouseMoveEvent(event);
        return;
    }

    if ((event->pos() - m_dragStartPos).manhattanLength() < QApplication::startDragDistance()) 
    {
        QWidget::mouseMoveEvent(event);
        return;
    }

    startDrag();
    QWidget::mouseMoveEvent(event);
}

void Draggable::startDrag() 
{
    // 创建拖拽对象
    QDrag *drag = new QDrag(this);
    
    drag->setMimeData(m_customMimeData);
    
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
    drag->exec(Qt::CopyAction | Qt::MoveAction);

    m_customMimeData = nullptr;
}

void Draggable::setMimeData(QMimeData* mimeData) 
{
    // 清理之前的自定义 MimeData
    if (m_customMimeData) 
    {
        delete m_customMimeData;
    }
    m_customMimeData = mimeData;
}

void Draggable::setCustomData(const QJsonObject &data)
{
    m_customData = data;

    update();
}

QJsonObject Draggable::getCustomData() const
{
    return m_customData;
}