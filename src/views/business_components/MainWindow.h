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
};

#endif // MAINWINDOW_H