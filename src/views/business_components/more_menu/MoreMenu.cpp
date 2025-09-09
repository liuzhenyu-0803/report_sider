#include "MoreMenu.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QColor>
#include <QFrame>
#include "QcIconButton.h"

MoreMenu::MoreMenu(QWidget *parent)
    : MicroUI::QcFrame(parent)
{
    setupUI();
}

MoreMenu::~MoreMenu() = default;

void MoreMenu::setupUI()
{
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    setBorderRadius(4);
    setBorderSides(MicroUI::QcFrame::BorderAll);
    setBorderColorParams("border/border_tertairy");
    setBackgroundColorParams("#FFFFFF");

    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);

    auto titleFrame = new MicroUI::QcFrame(this);
    titleFrame->setFixedHeight(30);
    auto titleLayout = new QHBoxLayout(titleFrame);
    titleLayout->setContentsMargins(8, 0, 6, 0);
    m_titleLabel = new MicroUI::QcLabel(titleFrame);
    m_titleLabel->setText("More Options");
    m_titleLabel->setType(MicroUI::QcLabel::LabelType::Title);
    auto closeButton = new MicroUI::QcIconButton();
    closeButton->SetIconPath(":/images/close.svg");
    titleLayout->addWidget(m_titleLabel);
    titleLayout->addWidget(closeButton);
    
    // 连接关闭按钮点击事件
    connect(closeButton, &MicroUI::QcIconButton::clicked, this, [this]() {
        setVisible(false);
    });

    m_contentFrame = new QFrame(this);
    auto contentLayout = new QVBoxLayout(m_contentFrame);
    contentLayout->setContentsMargins(8, 3, 8, 8);
    contentLayout->setSpacing(0);

    layout->addWidget(titleFrame);
    layout->addWidget(m_contentFrame);
}

QFrame *MoreMenu::getContentFrame()
{
    return m_contentFrame;
}

QLayout *MoreMenu::getContentLayout()
{
    return m_contentFrame->layout();
}

void MoreMenu::setTitle(const QString &title)
{
    if (m_titleLabel) {
        m_titleLabel->setText(title);
    }
}
