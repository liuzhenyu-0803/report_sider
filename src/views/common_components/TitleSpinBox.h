#ifndef TITLESPOINBOX_H
#define TITLESPOINBOX_H

#include "views/common_components/SpinBox.h"
#include "QcLabel.h"
#include <QVBoxLayout>
#include <QWidget>

class TitleSpinBox : public QWidget
{
    Q_OBJECT

public:
    explicit TitleSpinBox(QWidget *parent = nullptr);

    void setTitle(const QString &title);
    void setEnabled(bool enabled);

    int value() const;
    void setValue(int value);

    void setRange(int min, int max);

signals:
    void valueChanged(int newValue);

private:
    MicroUI::QcLabel *m_titleLabel;
    SpinBox *m_spinBox;
};

#endif // TITLESPOINBOX_H