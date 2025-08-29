#include "FieldTabPageFrame.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "views/business_components/group/field_group/TemperatureUnitFieldGroup.h"
#include "views/business_components/group/field_group/NoteFieldGroup.h"
#include "views/business_components/group/field_group/ImagePropertyFieldGroup.h"

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
    layout->setSpacing(16);

    // 创建测温单元组
    auto temperatureUnitGroup = new TemperatureUnitFieldGroup(m_contentWidget);
    layout->addWidget(temperatureUnitGroup);

    // 创建备注组
    auto noteGroup = new NoteFieldGroup(m_contentWidget);
    layout->addWidget(noteGroup);

    // 创建图片属性组
    auto imagePropertyGroup = new ImagePropertyFieldGroup(m_contentWidget);
    layout->addWidget(imagePropertyGroup);

    layout->addStretch();
}