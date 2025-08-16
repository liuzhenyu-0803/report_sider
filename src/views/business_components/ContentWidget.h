#pragma once
#include <QWidget>
#include <QVBoxLayout>

// 前置声明
class ThermalImageIndex;
class TabFrame;

class ContentWidget : public QWidget {
    Q_OBJECT
public:
    ContentWidget(QWidget *parent = nullptr);
    ~ContentWidget();

private:
    void setupUI();
    
    QVBoxLayout *m_layout;
    ThermalImageIndex *m_thermalImageIndex;
    TabFrame *m_tabFrame;
};