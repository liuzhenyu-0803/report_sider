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

    void setMimeData(QMimeData* mimeData);
    void setCustomData(const QVariant& data);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

    virtual QMimeData* getMimeData() const { return nullptr; };

    virtual void loadData() {};

    QVariant getCustomData() const;

private:
    void startDrag();
    
private:
    QPoint m_dragStartPos;
    QMimeData* m_customMimeData = nullptr;
    QVariant m_customData;
};