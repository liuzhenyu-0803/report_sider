#pragma once

#include <QWidget>
#include <QVariant>
#include <QTextDocument>
#include <QMimeData>

class Draggable : public QWidget
{
    Q_OBJECT

public:
    explicit Draggable(QWidget *parent = nullptr);
    virtual ~Draggable();

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