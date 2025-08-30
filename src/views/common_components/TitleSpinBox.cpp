#include "TitleSpinBox.h"

TitleSpinBox::TitleSpinBox(QWidget *parent)
    : QWidget(parent)
{

    m_titleLabel = new QLabel(this);
    m_spinBox = new SpinBox(this);

    auto layout = new QVBoxLayout(this);
    layout->addWidget(m_titleLabel);
    layout->addWidget(m_spinBox);

    connect(m_spinBox, QOverload<int>::of(&SpinBox::valueChanged), this, &TitleSpinBox::valueChanged);
}

int TitleSpinBox::value() const
{
    return m_spinBox->value();
}

void TitleSpinBox::setValue(int value)
{
    m_spinBox->setValue(value);
}

void TitleSpinBox::setTitle(const QString &title)
{
    m_titleLabel->setText(title);
}
