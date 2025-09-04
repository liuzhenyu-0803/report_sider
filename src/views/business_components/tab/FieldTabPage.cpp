#include "FieldTabPage.h"
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
#include "views/business_components/group/Group.h"

FieldTabPage::FieldTabPage(QWidget *parent)
    : TabPage(parent)
{

}

FieldTabPage::~FieldTabPage()
{
}

void FieldTabPage::loadContent()
{
    auto layout = new QVBoxLayout(m_contentWidget);
    m_contentWidget->setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(16);

    // 创建测温单元组
    m_temperatureUnitGroup = new TemperatureUnitFieldGroup(m_contentWidget);
    layout->addWidget(m_temperatureUnitGroup);

    // 创建备注组
    m_noteGroup = new NoteFieldGroup(m_contentWidget);
    layout->addWidget(m_noteGroup);

    // 创建图片属性组
    m_imagePropertyGroup = new ImagePropertyFieldGroup(m_contentWidget);
    layout->addWidget(m_imagePropertyGroup);

    layout->addStretch();
    
    // 连接信号槽
    connect(m_temperatureUnitGroup, &Group::groupExpanded, this, &FieldTabPage::onGroupExpanded);
    connect(m_noteGroup, &Group::groupExpanded, this, &FieldTabPage::onGroupExpanded);
    connect(m_imagePropertyGroup, &Group::groupExpanded, this, &FieldTabPage::onGroupExpanded);
    
    // 设置默认状态：只展开第一个group
    m_temperatureUnitGroup->setExpanded(true);
    m_noteGroup->setExpanded(false);
    m_imagePropertyGroup->setExpanded(false);
}

void FieldTabPage::onGroupExpanded(Group* expandedGroup)
{
    // 收起其他所有group
    if (expandedGroup != m_temperatureUnitGroup) {
        m_temperatureUnitGroup->setExpanded(false);
    }
    if (expandedGroup != m_noteGroup) {
        m_noteGroup->setExpanded(false);
    }
    if (expandedGroup != m_imagePropertyGroup) {
        m_imagePropertyGroup->setExpanded(false);
    }
}