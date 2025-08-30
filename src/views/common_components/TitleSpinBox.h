#ifndef TITLESPOINBOX_H
#define TITLESPOINBOX_H

#include "views/common_components/SpinBox.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class TitleSpinBox : public QWidget
{
    Q_OBJECT

public:
    explicit TitleSpinBox(QWidget *parent = nullptr);

    void setTitle(const QString &title);

    int value() const;
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    QLabel *m_titleLabel;
    SpinBox *m_spinBox;
};

#endif // TITLESPOINBOX_H