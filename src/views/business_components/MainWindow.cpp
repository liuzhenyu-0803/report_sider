#include "MainWindow.h"

#include "system_tray_icon/SystemTrayIcon.h"
#include "QcStyleManager.h"
#include "QcLabel.h"
#include "QcIconButton.h"
#include "QcFrame.h"

#include <QApplication>
#include <QPainter>
#include <QPainterPath>
#include <QKeyEvent>
#include <QToolTip>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{ 
    resize(360, 891);

    setWindowFlags(Qt::FramelessWindowHint);

    setAttribute(Qt::WA_TranslucentBackground);

    setMouseTracking(true);   

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    
    m_titleBar = createTitleBar();
    mainLayout->addWidget(m_titleBar);
    
    m_contentWidget = new ContentWidget();
    mainLayout->addWidget(m_contentWidget, 1);
    
    m_systemTrayIcon = new SystemTrayIcon(this);
    m_systemTrayIcon->setMainWindow(this);

    // 初始化自动收起功能
    m_autoHideTimer = new QTimer(this);
    m_autoHideTimer->setSingleShot(true);
    m_autoHideTimer->setInterval(1000); // 1秒延迟
    connect(m_autoHideTimer, &QTimer::timeout, this, &MainWindow::onAutoHideTimer);
    
    m_hideAnimation = new QPropertyAnimation(this, "geometry");
    m_hideAnimation->setDuration(300);
    connect(m_hideAnimation, &QPropertyAnimation::finished, this, &MainWindow::onHideAnimation);
    
    m_showAnimation = new QPropertyAnimation(this, "geometry");
    m_showAnimation->setDuration(300);
    connect(m_showAnimation, &QPropertyAnimation::finished, this, &MainWindow::onShowAnimation);

    // 安装全局事件过滤器来监听鼠标移动
    qApp->installEventFilter(this);

    REGISTER_QSS(this, ":/qss/business.qss");
}

MainWindow::~MainWindow() = default;

QWidget* MainWindow::createTitleBar()
{
    auto titleBar = new MicroUI::QcFrame();
    titleBar->setFixedHeight(40);
    titleBar->setBorderSides(MicroUI::QcFrame::BorderSide::BorderBottom);
    titleBar->setBorderColorParams("border/border_secondary");

    auto titleLayout = new QHBoxLayout(titleBar);
    titleLayout->setContentsMargins(15, 0, 8, 0);
    titleLayout->setSpacing(12);

    auto iconLabel = new QLabel();
    iconLabel->setFixedSize(24, 24);
    iconLabel->setPixmap(QPixmap(":/images/logo.png").scaled(iconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    titleLayout->addWidget(iconLabel);

    auto titleLabel = new MicroUI::QcLabel();
    titleLabel->setMinimumWidth(1);
    titleLabel->setText(tr("ReportDocumentAssiName"));
    titleLabel->setType(MicroUI::QcLabel::LabelType::H2Title);
    titleLayout->addWidget(titleLabel);
    
    titleLayout->addStretch();

    m_pinBtn = new MicroUI::QcIconButton();
    m_pinBtn->setFixedSize(24, 24);
    m_pinBtn->SetIconPath(":/images/pin.svg");
    auto minimizeBtn = new MicroUI::QcIconButton();
    minimizeBtn->setFixedSize(24, 24);
    minimizeBtn->SetIconPath(":/images/min.svg");
    auto closeBtn = new MicroUI::QcIconButton();
    closeBtn->setFixedSize(24, 24);
    closeBtn->SetIconPath(":/images/close.svg");

    titleLayout->addWidget(m_pinBtn);
    titleLayout->addWidget(minimizeBtn);
    titleLayout->addWidget(closeBtn);
    
    connect(minimizeBtn, &QPushButton::clicked, this, &MainWindow::onMinimizeWindow);
    connect(m_pinBtn, &QPushButton::clicked, this, &MainWindow::onTogglePinWindow);
    connect(closeBtn, &QPushButton::clicked, this, &MainWindow::onCloseWindow);
    
    return titleBar;
}

void MainWindow::mousePressEvent(QMouseEvent *event) 
{
    if (event->button() == Qt::LeftButton) 
    {
        ResizeDirection direction = getResizeDirection(event->pos());
        
        if (direction != None) 
        {   
            m_isResizing = true;
            m_resizeDirection = direction;
            m_dragPosition = event->globalPos();
            m_originalGeometry = geometry();
            event->accept();
        } 
        else 
        {
            QRect titleBarRect = m_titleBar->geometry();
            if (titleBarRect.contains(event->pos())) 
            {
                m_isDragging = true;
                m_dragPosition = event->globalPos() - frameGeometry().topLeft();
                event->accept();
            }
        }
    }
    QWidget::mousePressEvent(event);
}

MainWindow::ResizeDirection MainWindow::getResizeDirection(const QPoint &pos) 
{
    ResizeDirection direction = None;
    
    if (pos.x() <= RESIZE_BORDER_WIDTH) 
    {
        direction = static_cast<ResizeDirection>(direction | Left);
    } 
    else if (pos.x() >= width() - RESIZE_BORDER_WIDTH) 
    {
        direction = static_cast<ResizeDirection>(direction | Right);
    }
    
    if (pos.y() <= RESIZE_BORDER_WIDTH) 
    {
        direction = static_cast<ResizeDirection>(direction | Top);
    } 
    else if (pos.y() >= height() - RESIZE_BORDER_WIDTH) 
    {
        direction = static_cast<ResizeDirection>(direction | Bottom);
    }
    
    return direction;
}

void MainWindow::updateCursor(ResizeDirection direction) 
{
    switch (direction) 
    {
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

void MainWindow::performResize(const QPoint &globalPos) 
{
    if (!m_isResizing || m_resizeDirection == None) return;
    
    QRect newGeometry = m_originalGeometry;
    QPoint delta = globalPos - m_dragPosition;
    
    if (m_resizeDirection & Left) 
    {
        newGeometry.setLeft(m_originalGeometry.left() + delta.x());
    }
    if (m_resizeDirection & Right) 
    {
        newGeometry.setRight(m_originalGeometry.right() + delta.x());
    }
    if (m_resizeDirection & Top) 
    {
        newGeometry.setTop(m_originalGeometry.top() + delta.y());
    }
    if (m_resizeDirection & Bottom) 
    {
        newGeometry.setBottom(m_originalGeometry.bottom() + delta.y());
    }
     
    if (newGeometry.width() < 300) 
    {
        if (m_resizeDirection & Left) 
        {
            newGeometry.setLeft(newGeometry.right() - 300);
        } 
        else 
        {
            newGeometry.setRight(newGeometry.left() + 300);
        }
    }
    
    if (newGeometry.height() < 200) 
    {
        if (m_resizeDirection & Top) 
        {
            newGeometry.setTop(newGeometry.bottom() - 200);
        } else 
        {
            newGeometry.setBottom(newGeometry.top() + 200);
        }
    }
    
    setGeometry(newGeometry);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QPoint globalPos = mouseEvent->globalPos();
        QRect windowRect = geometry();
        
        if (windowRect.contains(globalPos) && !m_isResizing && !m_isDragging)
        {
            QPoint localPos = mapFromGlobal(globalPos);
            ResizeDirection direction = getResizeDirection(localPos);
            updateCursor(direction);
        }
        else if (!windowRect.contains(globalPos))
        {
            setCursor(Qt::ArrowCursor);
        }
        
        // 处理自动收起窗口的鼠标检测
        if (m_isHidden && m_edgeDirection != NoEdge) {
            QRect expandedRect = getExpandedHitRect();
            if (expandedRect.contains(globalPos)) {
                showWindow();
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_isDragging = false;
        m_isResizing = false;
        m_resizeDirection = None;
        setCursor(Qt::ArrowCursor);
        
        // 拖拽结束后检查是否贴边
        if (isNearScreenEdge()) {
            m_normalGeometry = geometry();
            m_edgeDirection = NoEdge;
            
            // 获取整个桌面的边界
            QRect desktopGeometry;
            QList<QScreen*> screens = QApplication::screens();
            if (!screens.isEmpty()) {
                desktopGeometry = screens.first()->geometry();
                for (QScreen* screen : screens) {
                    desktopGeometry = desktopGeometry.united(screen->geometry());
                }
            } else {
                desktopGeometry = QApplication::primaryScreen()->geometry();
            }
            
            QRect windowGeometry = geometry();
            
            // 判断贴边方向（只考虑整个桌面的边界）
            if (windowGeometry.left() <= desktopGeometry.left() + EDGE_THRESHOLD) {
                m_edgeDirection = LeftEdge;
            } else if (windowGeometry.right() >= desktopGeometry.right() - EDGE_THRESHOLD) {
                m_edgeDirection = RightEdge;
            } else if (windowGeometry.top() <= desktopGeometry.top() + EDGE_THRESHOLD) {
                m_edgeDirection = TopEdge;
            } else if (windowGeometry.bottom() >= desktopGeometry.bottom() - EDGE_THRESHOLD) {
                m_edgeDirection = BottomEdge;
            }
        } else {
            m_edgeDirection = NoEdge;
        }
    }
    QWidget::mouseReleaseEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) 
{
    if (m_isResizing && (event->buttons() & Qt::LeftButton)) 
    {
        performResize(event->globalPos());
        event->accept();
    }
    else if (m_isDragging && (event->buttons() & Qt::LeftButton))
    {
        move(event->globalPos() - m_dragPosition);
        // 检查拖拽结束后是否贴边
        if (isNearScreenEdge()) {
            m_normalGeometry = geometry();
        }
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}

void MainWindow::onCloseWindow() 
{
    hide();
}

void MainWindow::onMinimizeWindow() 
{
    showMinimized();
}

void MainWindow::onTogglePinWindow()
{
    if (windowFlags() & Qt::WindowStaysOnTopHint)
    {
        setWindowFlag(Qt::WindowStaysOnTopHint, false);
    } else
    {
        setWindowFlag(Qt::WindowStaysOnTopHint, true);
    }
    show();
}

void MainWindow::paintEvent(QPaintEvent *event) 
{
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    QPainterPath path;
    path.addRoundedRect(rect(), 10, 10); 
    
    painter.fillPath(path, QColor("#fafbff"));
    
    QPen pen(QColor("#e0e1e5"));
    pen.setWidth(1);
    painter.setPen(pen);
    painter.drawPath(path);
}

// 自动收起功能实现
bool MainWindow::isNearScreenEdge() const
{
    // 获取所有屏幕的整体桌面几何信息
    QRect desktopGeometry;
    QList<QScreen*> screens = QApplication::screens();
    
    // 计算整个桌面的边界
    if (!screens.isEmpty()) {
        desktopGeometry = screens.first()->geometry();
        for (QScreen* screen : screens) {
            desktopGeometry = desktopGeometry.united(screen->geometry());
        }
    } else {
        // 后备方案：使用主屏幕
        desktopGeometry = QApplication::primaryScreen()->geometry();
    }
    
    QRect windowGeometry = geometry();
    
    // 只有在整个桌面的真正边界才认为是贴边
    return (windowGeometry.left() <= desktopGeometry.left() + EDGE_THRESHOLD ||
            windowGeometry.right() >= desktopGeometry.right() - EDGE_THRESHOLD ||
            windowGeometry.top() <= desktopGeometry.top() + EDGE_THRESHOLD ||
            windowGeometry.bottom() >= desktopGeometry.bottom() - EDGE_THRESHOLD);
}

void MainWindow::startAutoHideTimer()
{
    if (m_edgeDirection != NoEdge && !m_isHidden) {
        m_autoHideTimer->start();
    }
}

void MainWindow::stopAutoHideTimer()
{
    m_autoHideTimer->stop();
}

void MainWindow::hideWindow()
{
    if (m_isHidden || m_edgeDirection == NoEdge) return;
    
    QRect currentGeometry = geometry();
    QRect targetGeometry = currentGeometry;
    
    // 获取整个桌面的边界
    QRect desktopGeometry;
    QList<QScreen*> screens = QApplication::screens();
    if (!screens.isEmpty()) {
        desktopGeometry = screens.first()->geometry();
        for (QScreen* screen : screens) {
            desktopGeometry = desktopGeometry.united(screen->geometry());
        }
    } else {
        desktopGeometry = QApplication::primaryScreen()->geometry();
    }
    
    switch (m_edgeDirection) {
        case LeftEdge:
            // 收起到左边，只保留3像素宽度
            targetGeometry.setLeft(desktopGeometry.left() - currentGeometry.width() + HIDE_WIDTH);
            targetGeometry.setRight(desktopGeometry.left() + HIDE_WIDTH);
            break;
        case RightEdge:
            // 收起到右边，只保留3像素宽度
            targetGeometry.setLeft(desktopGeometry.right() - HIDE_WIDTH);
            targetGeometry.setRight(desktopGeometry.right() + currentGeometry.width() - HIDE_WIDTH);
            break;
        case TopEdge:
            // 收起到顶部，只保留3像素高度
            targetGeometry.setTop(desktopGeometry.top() - currentGeometry.height() + HIDE_WIDTH);
            targetGeometry.setBottom(desktopGeometry.top() + HIDE_WIDTH);
            break;
        case BottomEdge:
            // 收起到底部，只保留3像素高度
            targetGeometry.setTop(desktopGeometry.bottom() - HIDE_WIDTH);
            targetGeometry.setBottom(desktopGeometry.bottom() + currentGeometry.height() - HIDE_WIDTH);
            break;
        default:
            return;
    }
    
    m_hideAnimation->setStartValue(currentGeometry);
    m_hideAnimation->setEndValue(targetGeometry);
    m_hideAnimation->start();
}

QRect MainWindow::getExpandedHitRect() const
{
    QRect currentGeometry = geometry();
    QRect expandedRect = currentGeometry;
    const int EXPAND_SIZE = 50; // 扩展检测区域50像素，方便鼠标触发
    
    switch (m_edgeDirection) {
        case LeftEdge:
            expandedRect.setRight(currentGeometry.right() + EXPAND_SIZE);
            break;
        case RightEdge:
            expandedRect.setLeft(currentGeometry.left() - EXPAND_SIZE);
            break;
        case TopEdge:
            expandedRect.setBottom(currentGeometry.bottom() + EXPAND_SIZE);
            break;
        case BottomEdge:
            expandedRect.setTop(currentGeometry.top() - EXPAND_SIZE);
            break;
        default:
            break;
    }
    
    return expandedRect;
}

void MainWindow::showWindow()
{
    if (!m_isHidden || m_edgeDirection == NoEdge) return;
    
    QRect currentGeometry = geometry();
    
    m_showAnimation->setStartValue(currentGeometry);
    m_showAnimation->setEndValue(m_normalGeometry);
    m_showAnimation->start();
}

void MainWindow::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    stopAutoHideTimer();
    if (m_isHidden) {
        showWindow();
    }
    QWidget::enterEvent(event);
}

void MainWindow::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    if (isNearScreenEdge()) {
        startAutoHideTimer();
    }
    QWidget::leaveEvent(event);
}

void MainWindow::onAutoHideTimer()
{
    hideWindow();
}

void MainWindow::onShowAnimation()
{
    m_isHidden = false;
}

void MainWindow::onHideAnimation()
{
    m_isHidden = true;
}