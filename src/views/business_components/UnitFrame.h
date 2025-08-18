#ifndef UNITFRAME_H
#define UNITFRAME_H

#include <QFrame>

class UnitFrame : public QFrame
{
    Q_OBJECT

public:
    explicit UnitFrame(QWidget *parent = nullptr);
    virtual ~UnitFrame();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // UNITFRAME_H