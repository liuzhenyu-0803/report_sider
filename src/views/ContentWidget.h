#pragma once
#include <QWidget>
#include <QList>

// 前置声明
class FlowLayout;
class ImageElementViewModel;
class HtmlElementViewModel;
class Element;
class ImageElement;
class HtmlElement;

class ContentWidget : public QWidget {
    Q_OBJECT
public:
    ContentWidget(QWidget *parent = nullptr);
    ~ContentWidget();

private:
    void setupUI();
    
    FlowLayout *m_layout;
    QList<ImageElementViewModel*> m_imageViewModels;
    QList<HtmlElementViewModel*> m_htmlViewModels;
    QList<Element*> m_elements;
};