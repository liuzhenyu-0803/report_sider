#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include "ContentWidget.h"

class SystemTrayIcon;

class MainWindow : public QWidget 
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void closeWindow();
    void minimizeWindow();
    void togglePinWindow();

private:
    void createTitleBar();
    
    enum ResizeDirection {
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
    
    QWidget *m_titleBar = nullptr;
    QLabel *m_iconLabel = nullptr;
    QLabel *m_titleLabel = nullptr;
    QPushButton *m_minimizeBtn = nullptr;
    QPushButton *m_pinBtn = nullptr;
    QPushButton *m_closeBtn = nullptr;
    ContentWidget *m_contentWidget = nullptr;
    SystemTrayIcon *m_systemTrayIcon = nullptr;
    
    QPoint m_dragPosition;
    bool m_isDragging = false;
    bool m_isResizing = false;
    ResizeDirection m_resizeDirection = ResizeDirection::None;
    QRect m_originalGeometry;
    static const int RESIZE_BORDER_WIDTH = 5;
};