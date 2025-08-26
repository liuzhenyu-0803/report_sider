#pragma once

#include <QWidget>
#include <QVariant>
#include <QTextDocument>
#include <QMimeData>

class ElementFrame : public QWidget
{
    Q_OBJECT

public:
    explicit ElementFrame(QWidget *parent = nullptr);
    virtual ~ElementFrame();
    
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

    // 子类实现：返回拖拽时的 MimeData
    virtual QMimeData* getMimeData() const = 0;

    virtual void loadData() = 0;

private:
    void startDrag();
    
private:
    QPoint m_dragStartPos;
};