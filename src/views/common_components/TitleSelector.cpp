#include "TitleSelector.h"

TitleSelector::TitleSelector(QWidget *parent)
    : QWidget(parent)
{
    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(3);

    m_titleLabel = new MicroUI::QcLabel(this);
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
