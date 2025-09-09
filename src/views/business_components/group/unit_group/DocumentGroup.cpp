#include "DocumentGroup.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QEvent>

#include "QcLabel.h"
#include "models/model.h"
#include "views/business_components/draggable/Draggable.h"
#include "views/business_components/group/Group.h"
#include "views/common_components/FlowLayout.h"
#include "views/business_components/draggable/unit_draggable/SummaryTableDraggable.h"
#include "views/business_components/draggable/unit_draggable/CoverTableDraggable.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

DocumentGroup::DocumentGroup(QWidget *parent)
    : UnitGroup(parent)
{
    // 初始化DocumentGroup
    // 设置组标题
    setGroupTitle(tr("DocumentName"));
}

DocumentGroup::~DocumentGroup()
{
    // 析构函数
}

QList<QWidget*> DocumentGroup::getElements()
{
    // 直接创建并返回元素列表
    QList<QWidget*> elements;
    elements.append(new SummaryTableDraggable(this));
    elements.append(new CoverTableDraggable(this));
    return elements;
}