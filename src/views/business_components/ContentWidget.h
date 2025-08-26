#pragma once

#include <QWidget>
#include <QVBoxLayout>

class ThermalImageIndex;
class TabFrame;

class ContentWidget : public QWidget 
{
    Q_OBJECT

public:
    ContentWidget(QWidget *parent = nullptr);
    ~ContentWidget();

private:
    void initUI();
    
    QVBoxLayout *m_layout = nullptr;
    ThermalImageIndex *m_thermalImageIndex = nullptr;
    TabFrame *m_tabFrame = nullptr;
};