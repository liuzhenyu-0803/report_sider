#pragma once

#include <QSystemTrayIcon>
#include <QMenu>
#include <QWidget>

class SystemTrayIcon : public QSystemTrayIcon {
    Q_OBJECT

public:
    explicit SystemTrayIcon(QWidget *parent = nullptr);
    ~SystemTrayIcon();

private slots:
    void onActivated(QSystemTrayIcon::ActivationReason reason);
    void showMainWindow();
    void exitApplication();

private:
    void createActions();
    void createTrayIcon();

    QWidget *m_mainWindow;
    QMenu *m_trayIconMenu;
    QAction *m_showAction;
    QAction *m_exitAction;
};