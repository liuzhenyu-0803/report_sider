#include "UnitTabPageFrame.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "views/business_components/group/unit_group/UnitImageGroupFrame.h"
#include "views/business_components/group/unit_group/ChartGroupFrame.h"
#include "views/business_components/group/unit_group/TemperatureGroupFrame.h"
#include "views/business_components/group/unit_group/NoteGroupFrame.h"
#include "views/business_components/group/unit_group/ImagePropertyGroupFrame.h"

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

    // 添加图像组
    layout->addWidget(new UnitImageGroupFrame(m_contentWidget));

    // 添加图表组
    layout->addWidget(new ChartGroupFrame(m_contentWidget));

    // 添加测温组
    layout->addWidget(new TemperatureGroupFrame(m_contentWidget));

    // 添加备注组
    layout->addWidget(new NoteGroupFrame(m_contentWidget));

    // 添加图片属性组
    layout->addWidget(new ImagePropertyGroupFrame(m_contentWidget));

    layout->addStretch();
}