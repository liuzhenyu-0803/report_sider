#include "UnitTabPageFrame.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "views/business_components/group/unit_group/UnitImageGroupFrame.h"

UnitTabPageFrame::UnitTabPageFrame(QWidget *parent)
    : TabPageFrame(parent)
{
    loadContent();
}

UnitTabPageFrame::~UnitTabPageFrame()
{
}

void UnitTabPageFrame::loadContent()
{
    auto layout = new QVBoxLayout(m_contentWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(20);
    m_contentWidget->setLayout(layout);

    auto groupFrame = new UnitImageGroupFrame(m_contentWidget);
    layout->addWidget(groupFrame);

    groupFrame = new UnitImageGroupFrame(m_contentWidget);
    layout->addWidget(groupFrame);

    layout->addStretch();
}