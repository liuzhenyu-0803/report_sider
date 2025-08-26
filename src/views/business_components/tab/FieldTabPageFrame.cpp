#include "FieldTabPageFrame.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "views/business_components/group/field_group/FieldInfoGroupFrame.h"

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
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(20);

    auto groupFrame = new FieldInfoGroupFrame(m_contentWidget);
    layout->addWidget(groupFrame);

    groupFrame = new FieldInfoGroupFrame(m_contentWidget);
    layout->addWidget(groupFrame);

    layout->addStretch();
}