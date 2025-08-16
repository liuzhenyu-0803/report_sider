#pragma once

#include <QWidget>
#include <QVariant>

// 前置声明ViewModel类
class ElementViewModel;

class Element : public QWidget {
    Q_OBJECT

public:
    explicit Element(ElementViewModel *viewModel, QWidget *parent = nullptr);
    ~Element() override;
    
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    void startDrag();

protected:
    ElementViewModel *m_viewModel;
    
private:
    QPoint m_dragStartPos;
};