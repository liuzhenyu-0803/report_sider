#ifndef FIELDFRAME_H
#define FIELDFRAME_H

#include <QFrame>

class FieldFrame : public QFrame
{
    Q_OBJECT

public:
    explicit FieldFrame(QWidget *parent = nullptr);
    virtual ~FieldFrame();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // FIELDFRAME_H