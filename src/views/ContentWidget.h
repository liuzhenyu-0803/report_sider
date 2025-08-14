#pragma once
#include <QWidget>
#include <QList>

// 前置声明
class FlowLayout;
class ImageElementViewModel;
class HtmlElementViewModel;
class UrlsElementViewModel;
class Element;
class ImageElement;
class HtmlElement;
class UrlsElement;

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
    QList<UrlsElementViewModel*> m_urlsViewModels;
    QList<Element*> m_elements;
};