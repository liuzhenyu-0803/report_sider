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

};

#endif // SPINBOX_H