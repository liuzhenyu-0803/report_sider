#pragma once

#include <QWidget>
#include <QVariant>
#include <QTextDocument>

// 前置声明Model类
class ElementModel;

class Element : public QWidget
{
    Q_OBJECT

public:
    explicit Element(ElementModel *model, QWidget *parent = nullptr);
    virtual ~Element();
    
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    void startDrag();
    void paintHtmlElement(QPainter &p);
    void paintImageElement(QPainter &p);
    void paintUrlsElement(QPainter &p);

protected:
    ElementModel *m_model;
    
private:
    QPoint m_dragStartPos;
};