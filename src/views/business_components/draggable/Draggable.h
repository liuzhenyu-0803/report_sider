#pragma once

#include <QWidget>
#include <QVariant>
#include <QTextDocument>
#include <QMimeData>
#include <QJsonObject>

class Draggable : public QWidget
{
    Q_OBJECT

public:
    explicit Draggable(QWidget *parent = nullptr);
    virtual ~Draggable();

    void setMimeData(QMimeData* mimeData);
    void setCustomData(const QJsonObject& data);
    QJsonObject getCustomData() const;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

    // virtual void loadData() = 0;

private:
    void startDrag();
    
private:
    QPoint m_dragStartPos;
    QMimeData* m_customMimeData = nullptr;
    QJsonObject m_customData;
};