#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), isDragging(false) {
    
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    resize(800, 600);
    
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    setupCustomTitleBar();
    
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(titleBar);
    
    QWidget *contentArea = new QWidget();
    contentArea->setStyleSheet("background-color: #f0f0f0;");
    mainLayout->addWidget(contentArea, 1);
}

MainWindow::~MainWindow() = default;

void MainWindow::setupCustomTitleBar() {
    titleBar = new QWidget();
    titleBar->setFixedHeight(40);
    titleBar->setStyleSheet("background-color: #2c3e50;");
    
    QHBoxLayout *titleLayout = new QHBoxLayout(titleBar);
    titleLayout->setContentsMargins(10, 0, 5, 0);
    titleLayout->setSpacing(5);
    
    titleLabel = new QLabel("report_sider");
    titleLabel->setStyleSheet("color: white;");
    titleLayout->addWidget(titleLabel);
    
    titleLayout->addStretch();
    
    minimizeBtn = new QPushButton("-");
    maximizeBtn = new QPushButton("O");
    closeBtn = new QPushButton("X");
    
    minimizeBtn->setFixedSize(30, 30);
    maximizeBtn->setFixedSize(30, 30);
    closeBtn->setFixedSize(30, 30);
    
    titleLayout->addWidget(minimizeBtn);
    titleLayout->addWidget(maximizeBtn);
    titleLayout->addWidget(closeBtn);
    
    connect(minimizeBtn, &QPushButton::clicked, this, &MainWindow::minimizeWindow);
    connect(maximizeBtn, &QPushButton::clicked, this, &MainWindow::maximizeWindow);
    connect(closeBtn, &QPushButton::clicked, this, &MainWindow::closeWindow);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QRect titleBarRect = titleBar->geometry();
        if (titleBarRect.contains(event->pos())) {
            isDragging = true;
            dragPosition = event->globalPos() - frameGeometry().topLeft();
            event->accept();
        }
    }
    QMainWindow::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (isDragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::closeWindow() {
    close();
}

void MainWindow::minimizeWindow() {
    showMinimized();
}

void MainWindow::maximizeWindow() {
    if (isMaximized()) {
        showNormal();
        maximizeBtn->setText("O");
    } else {
        showMaximized();
        maximizeBtn->setText("R");
    }
}