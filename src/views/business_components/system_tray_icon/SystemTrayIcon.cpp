#include "SystemTrayIcon.h"
#include <QIcon>
#include <QApplication>
#include <QMessageBox>


SystemTrayIcon::SystemTrayIcon(QWidget *parent)
    : QSystemTrayIcon(parent) 
{
    createActions();
    createTrayIcon();
    
    setIcon(QIcon(":/images/test.png"));
    
    connect(this, &QSystemTrayIcon::activated, this, &SystemTrayIcon::onActivated);
    
    show();
}

SystemTrayIcon::~SystemTrayIcon() 
{
    // Destructor
}

void SystemTrayIcon::setMainWindow(QWidget *mainWindow)
{
    m_mainWindow = mainWindow;
}

void SystemTrayIcon::createActions() 
{
    m_showAction = new QAction("Show Main Window", this);
    connect(m_showAction, &QAction::triggered, this, &SystemTrayIcon::showMainWindow);
    
    m_exitAction = new QAction("Exit", this);
    connect(m_exitAction, &QAction::triggered, this, &SystemTrayIcon::exitApplication);
}

void SystemTrayIcon::createTrayIcon() 
{
    m_trayIconMenu = new QMenu();
    m_trayIconMenu->addAction(m_showAction);
    m_trayIconMenu->addSeparator();
    m_trayIconMenu->addAction(m_exitAction);
    
    setContextMenu(m_trayIconMenu);
}

void SystemTrayIcon::onActivated(QSystemTrayIcon::ActivationReason reason) 
{
    switch (reason) 
    {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        showMainWindow();
        break;
    default:
        break;
    }
}

void SystemTrayIcon::showMainWindow() 
{
    if (m_mainWindow) 
    {
        if (m_mainWindow->isMinimized()) 
        {
            m_mainWindow->showNormal();
        } 
        else 
        {
            m_mainWindow->show();
        }
        m_mainWindow->raise();
        m_mainWindow->activateWindow();
    }
}

void SystemTrayIcon::exitApplication() 
{
    QApplication::quit();
}