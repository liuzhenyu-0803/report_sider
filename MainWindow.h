#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void closeWindow();
    void minimizeWindow();
    void maximizeWindow();

private:
    void setupCustomTitleBar();
    
    QWidget *centralWidget;
    QWidget *titleBar;
    QLabel *titleLabel;
    QPushButton *minimizeBtn;
    QPushButton *maximizeBtn;
    QPushButton *closeBtn;
    
    QPoint dragPosition;
    bool isDragging;
};