#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include "ContentWidget.h"

// 前置声明
class SystemTrayIcon;

class MainWindow : public QWidget {
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
    void setupCustomTitleBar();
    
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
    
    QWidget *titleBar;
    QLabel *titleLabel;
    QPushButton *minimizeBtn;
    QPushButton *pinBtn;
    QPushButton *closeBtn;
    ContentWidget *contentWidget;
    SystemTrayIcon *m_systemTrayIcon;
    
    QPoint dragPosition;
    bool isDragging;
    bool isResizing;
    ResizeDirection resizeDirection;
    QRect originalGeometry;
    static const int RESIZE_BORDER_WIDTH = 5;
};