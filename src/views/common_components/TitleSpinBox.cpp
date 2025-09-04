#include "TitleSpinBox.h"

TitleSpinBox::TitleSpinBox(QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(3);

    m_titleLabel = new MicroUI::QcLabel(this);
    QFont font;
    font.setPixelSize(10);
    font.setBold(true);
    m_titleLabel->setFont(font);
    m_titleLabel->setFixedHeight(16);
    m_spinBox = new SpinBox(this);
    m_spinBox->setFixedHeight(28);

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

void TitleSpinBox::setRange(int min, int max)
{
    m_spinBox->setRange(min, max);
}

void TitleSpinBox::setTitle(const QString &title)
{
    m_titleLabel->setText(title);
}

void TitleSpinBox::setEnabled(bool enabled)
{
    m_spinBox->setEnabled(enabled);
}