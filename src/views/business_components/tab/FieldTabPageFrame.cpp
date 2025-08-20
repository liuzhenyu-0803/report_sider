#include "FieldTabPageFrame.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "views/business_components/group/FieldGroupFrame.h"

FieldTabPageFrame::FieldTabPageFrame(QWidget *parent)
    : TabPageFrame(parent)
{
    loadContent();
}

FieldTabPageFrame::~FieldTabPageFrame()
{
}

void FieldTabPageFrame::loadContent()
{
    auto layout = new QVBoxLayout(m_contentWidget);
    m_contentWidget->setLayout(layout);

    auto groupFrame = new FieldGroupFrame(m_contentWidget);
    layout->addWidget(groupFrame);

    groupFrame = new FieldGroupFrame(m_contentWidget);
    layout->addWidget(groupFrame);

    layout->addStretch();
}