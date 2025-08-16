#ifndef SPINBOX_H
#define SPINBOX_H

#include <QSpinBox>
#include <QString>

class SpinBox : public QSpinBox
{
    Q_OBJECT

public:
    explicit SpinBox(QWidget *parent = nullptr);
    virtual ~SpinBox();

private:
    void loadStyleSheet();

};

#endif // SPINBOX_H