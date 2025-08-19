#include "GroupFrame.h"
#include "../../models/GroupModel.h"
#include "../../models/ElementModel.h"
#include "../common_components/FlowLayout.h"
#include "ElementFrame.h"
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>

GroupFrame::GroupFrame(GroupModel* groupModel, QWidget *parent)
    : QFrame(parent), m_groupModel(groupModel)
{
    setupUI();
    createElementFrames();
}

GroupFrame::~GroupFrame()
{
}

void GroupFrame::setupUI() {
    // 设置样式
    setStyleSheet("GroupFrame { border: 1px solid gray; border-radius: 5px; margin: 5px; }");
    
    // 创建主布局
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(10, 10, 10, 10);
    m_mainLayout->setSpacing(10);
    
    // 创建组标签
    m_groupLabel = new QLabel(m_groupModel->getLabel(), this);
    m_groupLabel->setStyleSheet("font-weight: bold; font-size: 14px; margin-top: 5px;");
    m_mainLayout->addWidget(m_groupLabel);
    
    // 创建内容布局
    m_contentLayout = new QVBoxLayout();
    m_contentLayout->setAlignment(Qt::AlignTop);
    m_mainLayout->addLayout(m_contentLayout);
    
    setLayout(m_mainLayout);
}

void GroupFrame::createElementFrames() {
    if (!m_groupModel) return;
    
    // 获取元素模型列表
    QList<ElementModel*> elementModels = m_groupModel->getElementModels();
    
    // 创建流式布局用于放置元素
    FlowLayout *flowLayout = new FlowLayout(10, 10, 10);
    
    // 为每个元素模型创建ElementFrame
    for (ElementModel* elementModel : elementModels) {
        ElementFrame* elementFrame = new ElementFrame(elementModel, this);
        flowLayout->addWidget(elementFrame);
    }
    
    // 将流式布局添加到内容布局
    m_contentLayout->addLayout(flowLayout);
}