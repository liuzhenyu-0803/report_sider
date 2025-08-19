#include "UnitTabPageFrame.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "views/business_components/group/GroupFrame.h"

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
    m_contentWidget->setStyleSheet("background-color: green;");

    auto layout = new QVBoxLayout(m_contentWidget);
    m_contentWidget->setLayout(layout);

    auto groupFrame = new GroupFrame(m_contentWidget);
    layout->addWidget(groupFrame);

    groupFrame = new GroupFrame(m_contentWidget);
    layout->addWidget(groupFrame);

    layout->addStretch();
}