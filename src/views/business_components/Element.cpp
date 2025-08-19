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
#include "../../models/ElementModel.h"

Element::Element(ElementModel *model, QWidget *parent)
    : QWidget(parent), m_model(model) {
    setAttribute(Qt::WA_StyledBackground, true);
    // 设置固定大小为100x100
    setFixedSize(100, 100);
    // 启用鼠标跟踪
    setMouseTracking(true);
}

Element::~Element() = default;

void Element::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    
    // 根据模型类型绘制不同背景
    switch (m_model->getType()) {
    case ElementType::Html:
        p.setBrush(Qt::red);
        break;
    case ElementType::Image:
        p.setBrush(Qt::red);
        break;
    case ElementType::Urls:
        p.setBrush(Qt::blue);
        break;
    default:
        p.setBrush(Qt::red);
        break;
    }
    
    p.drawRect(rect()); // 绘制边框
    
    // 根据模型类型绘制特定内容
    switch (m_model->getType()) {
    case ElementType::Html:
        paintHtmlElement(p);
        break;
    case ElementType::Image:
        paintImageElement(p);
        break;
    case ElementType::Urls:
        paintUrlsElement(p);
        break;
    default:
        break;
    }
}

void Element::paintHtmlElement(QPainter &p) {
    // 从Model中获取HTML数据
    Data data = m_model->getData();
    
    // 如果有HTML内容则绘制HTML
    if (!data.html.isEmpty()) {
        // 使用QTextDocument来渲染HTML内容
        QTextDocument doc;
        doc.setHtml(data.html);
        doc.setTextWidth(width() - 10); // 留一些边距
        
        // 在元素中心绘制HTML内容
        p.translate(5, (height() - doc.size().height()) / 2);
        doc.drawContents(&p);
        p.translate(-5, -(height() - doc.size().height()) / 2);
    }
}

void Element::paintImageElement(QPainter &p) {
    // 从Model中获取图像数据
    Data data = m_model->getData();
    
    // 如果有图像则绘制图像
    if (!data.image.isNull()) {
        // 按比例缩放图像以适应元素大小
        QPixmap pixmap = QPixmap::fromImage(data.image.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        p.drawPixmap((width() - pixmap.width()) / 2, (height() - pixmap.height()) / 2, pixmap);
    }
}

void Element::paintUrlsElement(QPainter &p) {
    // 从Model中获取URLs数据
    Data data = m_model->getData();
    
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
        p.translate(-5, -(height() - doc.size().height()) / 2);
    }
}

void Element::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragStartPos = event->pos();
        
        // 将MimeData设置到剪切板中
        QMimeData *mimeData = m_model->getMimeData();
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
    
    // 通过Model获取MimeData
    QMimeData *mimeData = m_model->getMimeData();
    
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