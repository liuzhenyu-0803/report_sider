#pragma once
#include <QWidget>
#include <QList>

// 前置声明
class FlowLayout;
class ImageElementViewModel;
class Element;
class ImageElement;

class ContentWidget : public QWidget {
    Q_OBJECT
public:
    ContentWidget(QWidget *parent = nullptr);
    ~ContentWidget();

private:
    void setupUI();
    
    FlowLayout *m_layout;
    QList<ImageElementViewModel*> m_viewModels;
    QList<Element*> m_elements;
};