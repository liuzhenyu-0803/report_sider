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
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    setAttribute(Qt::WA_TranslucentBackground);

    resize(800, 600);
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

    auto iconLabel = new MicroUI::QcLabel();
    iconLabel->setFixedSize(24, 24);
    iconLabel->SetIconPath(":/images/logo.png");
    titleLayout->addWidget(iconLabel);

    auto titleLabel = new MicroUI::QcLabel();
    titleLabel->setText("report doc assistant");
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
        
        if (direction != None) {
            
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
        if (m_pinBtn) m_pinBtn->setText("P");
    } else
    {
        setWindowFlag(Qt::WindowStaysOnTopHint, true);
        if (m_pinBtn) m_pinBtn->setText("PIN");
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