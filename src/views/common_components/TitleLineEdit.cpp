#include "TitleLineEdit.h"

TitleLineEdit::TitleLineEdit(QWidget *parent)
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
    m_lineEdit = new MicroUI::QcLineEditFrame(this);
    m_lineEdit->setFixedHeight(28);

    layout->addWidget(m_titleLabel);
    layout->addWidget(m_lineEdit);
}

TitleLineEdit::~TitleLineEdit()
{
}

void TitleLineEdit::setTitle(const QString &title)
{
    m_titleLabel->setText(title);
}

void TitleLineEdit::setValidator(QValidator *v)
{
    m_lineEdit->setValidator(v);
}

void TitleLineEdit::setText(const QString &text)
{
    m_lineEdit->setText(text);
}

QString TitleLineEdit::getText() const
{
    return m_lineEdit->getText();
}
