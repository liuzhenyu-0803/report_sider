#include "TitleSelector.h"

TitleSelector::TitleSelector(QWidget *parent)
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
    m_selector = new MicroUI::QcSelector(this);
    m_selector->setFixedHeight(28);

    layout->addWidget(m_titleLabel);
    layout->addWidget(m_selector);

    connect(m_selector, SIGNAL(currentIndexChanged(int)), this, SIGNAL(currentIndexChanged()));
}

TitleSelector::~TitleSelector()
{
}

void TitleSelector::setTitle(const QString &title)
{
    m_titleLabel->setText(title);
}

void TitleSelector::addItem(const QString &text, const QVariant &userData)
{
    m_selector->addItem(text, userData);
}

void TitleSelector::addItems(const QStringList &texts)
{
    m_selector->addItems(texts);
}

int TitleSelector::currentIndex() const
{
    return m_selector->currentIndex();
}

QString TitleSelector::currentText() const
{
    return m_selector->currentText();
}

QVariant TitleSelector::currentData() const
{
    return m_selector->currentData();
}

void TitleSelector::setEnabled(bool enabled)
{
    m_selector->setEnabled(enabled);
}

bool TitleSelector::isEnabled() const
{
    return m_selector->isEnabled();
}
