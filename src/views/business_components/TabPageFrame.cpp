#include "TabPageFrame.h"
#include "../../models/ConfigModel.h"
#include "../../models/GroupModel.h"
#include "GroupFrame.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>

TabPageFrame::TabPageFrame(QWidget *parent)
    : QFrame(parent), m_configModel(nullptr)
{
    setupUI();
}

TabPageFrame::~TabPageFrame()
{
}

void TabPageFrame::setupUI() {
    // 创建主布局
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(10, 10, 10, 10);
    m_mainLayout->setSpacing(10);
    
    // 创建滚动区域
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    // 创建内容部件和布局
    QWidget *contentWidget = new QWidget();
    m_contentLayout = new QVBoxLayout(contentWidget);
    m_contentLayout->setAlignment(Qt::AlignTop);
    
    m_scrollArea->setWidget(contentWidget);
    m_mainLayout->addWidget(m_scrollArea);
    
    setLayout(m_mainLayout);
}

void TabPageFrame::loadConfig(const QString& configPath) {
    // 创建ConfigModel并加载配置
    m_configModel = new ConfigModel(this);
    m_configModel->loadConfig(configPath);
    
    // 创建组视图
    createGroupViews();
}

void TabPageFrame::createGroupViews() {
    if (!m_configModel) return;
    
    // 获取组模型列表
    QList<GroupModel*> groupModels = m_configModel->getGroupModels();
    
    // 为每个组模型创建GroupFrame
    for (GroupModel* groupModel : groupModels) {
        GroupFrame* groupFrame = new GroupFrame(groupModel, this);
        m_contentLayout->addWidget(groupFrame);
    }
}