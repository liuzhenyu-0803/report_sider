#pragma once

#include <QSystemTrayIcon>
#include <QMenu>
#include <QWidget>


class SystemTrayIcon : public QSystemTrayIcon 
{
    Q_OBJECT

public:
    explicit SystemTrayIcon(QWidget *parent = nullptr);
    ~SystemTrayIcon();

    void setMainWindow(QWidget *mainWindow);

private slots:
    void onActivated(QSystemTrayIcon::ActivationReason reason);
    void showMainWindow();
    void exitApplication();

private:
    void createActions();
    void createTrayIcon();

    QWidget *m_mainWindow = nullptr;
    QMenu *m_trayIconMenu = nullptr;
    QAction *m_showAction = nullptr;
    QAction *m_exitAction = nullptr;
};