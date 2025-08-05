#pragma once
#include <QWidget>

class ContentWidget : public QWidget {
    Q_OBJECT
public:
    ContentWidget(QWidget *parent = nullptr);
    ~ContentWidget();

private:
    void setupUI();
};