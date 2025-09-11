#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ContentWidget.h"
#include "MicroUI/QcIconButton.h"
#include "views/business_components/system_tray_icon/SystemTrayIcon.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QPropertyAnimation>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>


class MainWindow : public QWidget 
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onCloseWindow();
    void onMinimizeWindow();
    void onTogglePinWindow();
    void onAutoHideTimer();
    void onShowAnimation();
    void onHideAnimation();

private:
    QWidget* createTitleBar();
    
    enum ResizeDirection
    {
        None = 0,
        Left = 1,
        Right = 2,
        Top = 4,
        Bottom = 8,
        TopLeft = Top | Left,
        TopRight = Top | Right,
        BottomLeft = Bottom | Left,
        BottomRight = Bottom | Right
    };
    
    ResizeDirection getResizeDirection(const QPoint &pos);
    void updateCursor(ResizeDirection direction);
    void performResize(const QPoint &globalPos);
    
    // 自动收起功能相关函数
    bool isNearScreenEdge() const;
    void startAutoHideTimer();
    void stopAutoHideTimer();
    void hideWindow();
    void showWindow();
    QRect getExpandedHitRect() const;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    
    QWidget *m_titleBar = nullptr;
    MicroUI::QcIconButton *m_pinBtn = nullptr;
    ContentWidget *m_contentWidget = nullptr;
    SystemTrayIcon *m_systemTrayIcon = nullptr;
    
    QPoint m_dragPosition;
    bool m_isDragging = false;
    bool m_isResizing = false;
    ResizeDirection m_resizeDirection = ResizeDirection::None;
    QRect m_originalGeometry;
    static const int RESIZE_BORDER_WIDTH = 5;
    
    // 自动收起功能相关成员变量
    QTimer *m_autoHideTimer = nullptr;
    QPropertyAnimation *m_hideAnimation = nullptr;
    QPropertyAnimation *m_showAnimation = nullptr;
    bool m_isHidden = false;
    QRect m_normalGeometry;
    enum EdgeDirection
    {
        NoEdge = 0,
        LeftEdge = 1,
        RightEdge = 2,
        TopEdge = 3,
        BottomEdge = 4
    };
    EdgeDirection m_edgeDirection = NoEdge;
    static const int EDGE_THRESHOLD = 10; // 贴边检测阈值
    static const int HIDE_WIDTH = 3; // 收起后显示的宽度/高度，减少到3像素
};

#endif // MAINWINDOW_H