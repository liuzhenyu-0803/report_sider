#include "UnitTabPage.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "views/business_components/group/unit_group/UnitImageGroup.h"
#include "views/business_components/group/unit_group/ChartGroup.h"
#include "views/business_components/group/unit_group/TemperatureGroup.h"
#include "views/business_components/group/unit_group/NoteGroup.h"
#include "views/business_components/group/unit_group/ImagePropertyGroup.h"

#include "views/business_components/group/unit_group/DocumentGroup.h"

UnitTabPage::UnitTabPage(QWidget *parent)
    : TabPage(parent)
{
    
}

UnitTabPage::~UnitTabPage()
{

}

void UnitTabPage::loadContent()
{
    auto layout = new QVBoxLayout(m_contentWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(16);
    m_contentWidget->setLayout(layout);

    // 添加图像组
    layout->addWidget(new UnitImageGroup(m_contentWidget));

    // 添加图表组
    layout->addWidget(new ChartGroup(m_contentWidget));

    // 添加测温组
    layout->addWidget(new TemperatureGroup(m_contentWidget));

    // 添加备注组
    layout->addWidget(new NoteGroup(m_contentWidget));

    // 添加图片属性组
    layout->addWidget(new ImagePropertyGroup(m_contentWidget));

    layout->addWidget(new DocumentGroup(m_contentWidget));

    layout->addStretch();
}