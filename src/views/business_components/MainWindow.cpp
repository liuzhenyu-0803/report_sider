#include "MainWindow.h"
#include "SystemTrayIcon.h"
#include <QApplication>
#include <QPainter>
#include <QPainterPath>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), isDragging(false), isResizing(false), resizeDirection(None) {
    
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    setAttribute(Qt::WA_TranslucentBackground);

    resize(800, 600);
    setMouseTracking(true);

    QApplication::instance()->installEventFilter(this);
    
    // centralWidget = new QWidget(this);
    // QWidget基类无需 setCentralWidget
    
    setupCustomTitleBar();
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(titleBar);
    
    contentWidget = new ContentWidget();
    mainLayout->addWidget(contentWidget, 1);
    
    // 创建系统托盘图标
    m_systemTrayIcon = new SystemTrayIcon(this);
}

MainWindow::~MainWindow() = default;

void MainWindow::setupCustomTitleBar() {
    titleBar = new QWidget();
    titleBar->setFixedHeight(40);
    
    QHBoxLayout *titleLayout = new QHBoxLayout(titleBar);
    titleLayout->setContentsMargins(10, 0, 5, 0);
    titleLayout->setSpacing(5);
    
    titleLabel = new QLabel("report_sider");
    titleLayout->addWidget(titleLabel);
    
    titleLayout->addStretch();
    
    minimizeBtn = new QPushButton("-");
    pinBtn = new QPushButton("P");
    closeBtn = new QPushButton("X");
    
    minimizeBtn->setFixedSize(30, 30);
    pinBtn->setFixedSize(30, 30);
    closeBtn->setFixedSize(30, 30);
    
    titleLayout->addWidget(pinBtn);
    titleLayout->addWidget(minimizeBtn);
    titleLayout->addWidget(closeBtn);
    
    connect(minimizeBtn, &QPushButton::clicked, this, &MainWindow::minimizeWindow);
    connect(pinBtn, &QPushButton::clicked, this, &MainWindow::togglePinWindow);
    connect(closeBtn, &QPushButton::clicked, this, &MainWindow::closeWindow);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        ResizeDirection direction = getResizeDirection(event->pos());
        
        if (direction != None) {
            
            isResizing = true;
            resizeDirection = direction;
            dragPosition = event->globalPos();
            originalGeometry = geometry();
            event->accept();
        } else {
            QRect titleBarRect = titleBar->geometry();
            if (titleBarRect.contains(event->pos())) {
                isDragging = true;
                dragPosition = event->globalPos() - frameGeometry().topLeft();
                event->accept();
            }
        }
    }
    QWidget::mousePressEvent(event);
}

MainWindow::ResizeDirection MainWindow::getResizeDirection(const QPoint &pos) {
    ResizeDirection direction = None;
    
    if (pos.x() <= RESIZE_BORDER_WIDTH) {
        direction = static_cast<ResizeDirection>(direction | Left);
    } else if (pos.x() >= width() - RESIZE_BORDER_WIDTH) {
        direction = static_cast<ResizeDirection>(direction | Right);
    }
    
    if (pos.y() <= RESIZE_BORDER_WIDTH) {
        direction = static_cast<ResizeDirection>(direction | Top);
    } else if (pos.y() >= height() - RESIZE_BORDER_WIDTH) {
        direction = static_cast<ResizeDirection>(direction | Bottom);
    }
    
    return direction;
}

void MainWindow::updateCursor(ResizeDirection direction) {
    switch (direction) {
        case Left:
        case Right:
            setCursor(Qt::SizeHorCursor);
            break;
        case Top:
        case Bottom:
            setCursor(Qt::SizeVerCursor);
            break;
        case TopLeft:
        case BottomRight:
            setCursor(Qt::SizeFDiagCursor);
            break;
        case TopRight:
        case BottomLeft:
            setCursor(Qt::SizeBDiagCursor);
            break;
        default:
            setCursor(Qt::ArrowCursor);
            break;
    }
}

void MainWindow::performResize(const QPoint &globalPos) {
    if (!isResizing || resizeDirection == None) return;
    
    QRect newGeometry = originalGeometry;
    QPoint delta = globalPos - dragPosition;
    
    if (resizeDirection & Left) {
        newGeometry.setLeft(originalGeometry.left() + delta.x());
    }
    if (resizeDirection & Right) {
        newGeometry.setRight(originalGeometry.right() + delta.x());
    }
    if (resizeDirection & Top) {
        newGeometry.setTop(originalGeometry.top() + delta.y());
    }
    if (resizeDirection & Bottom) {
        newGeometry.setBottom(originalGeometry.bottom() + delta.y());
    }
    
    
    if (newGeometry.width() < 300) {
        if (resizeDirection & Left) {
            newGeometry.setLeft(newGeometry.right() - 300);
        } else {
            newGeometry.setRight(newGeometry.left() + 300);
        }
    }
    
    if (newGeometry.height() < 200) {
        if (resizeDirection & Top) {
            newGeometry.setTop(newGeometry.bottom() - 200);
        } else {
            newGeometry.setBottom(newGeometry.top() + 200);
        }
    }
    
    setGeometry(newGeometry);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QPoint globalPos = mouseEvent->globalPos();
        QRect windowRect = geometry();
        
        if (windowRect.contains(globalPos) && !isResizing && !isDragging) {
            QPoint localPos = mapFromGlobal(globalPos);
            ResizeDirection direction = getResizeDirection(localPos);
            updateCursor(direction);
        } else if (!windowRect.contains(globalPos)) {
            setCursor(Qt::ArrowCursor);
        }
    } else if (event->type() == QEvent::Paint && obj == titleBar) {
        // 处理标题栏的绘制事件
        QWidget *titleBarWidget = qobject_cast<QWidget*>(obj);
        if (titleBarWidget) {
            // 在标题栏底部绘制边框
            QPainter painter(titleBarWidget);
            QPen pen(QColor("#e0e1e5"));
            pen.setWidth(1);
            painter.setPen(pen);
            painter.drawLine(0, titleBarWidget->height() - 1, titleBarWidget->width(), titleBarWidget->height() - 1);
            
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
        isResizing = false;
        resizeDirection = None;
        setCursor(Qt::ArrowCursor);
    }
    QWidget::mouseReleaseEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (isResizing && (event->buttons() & Qt::LeftButton)) {
        performResize(event->globalPos());
        event->accept();
    } else if (isDragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}

void MainWindow::closeWindow() {
    // 隐藏窗口而不是关闭
    hide();
}

void MainWindow::minimizeWindow() {
    showMinimized();
}

void MainWindow::togglePinWindow() {
    if (windowFlags() & Qt::WindowStaysOnTopHint) {
        setWindowFlag(Qt::WindowStaysOnTopHint, false);
        pinBtn->setText("P");
    } else {
        setWindowFlag(Qt::WindowStaysOnTopHint, true);
        pinBtn->setText("PIN");
    }
    show(); // 重新显示窗口以应用更改
}
void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // 创建圆角矩形路径
    QPainterPath path;
    path.addRoundedRect(rect(), 10, 10); // 10像素的圆角半径
    
    // 设置背景色
    painter.fillPath(path, QColor("#fafbff"));
    
    // 设置边框
    QPen pen(QColor("#e0e1e5"));
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawPath(path);
}