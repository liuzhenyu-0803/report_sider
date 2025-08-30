#include "NoteGroup.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

NoteGroup::NoteGroup(QWidget *parent)
    : UnitGroup(parent)
{
    // 初始化NoteGroupFrame
    // 设置组标�?
    setGroupTitle("Note Group");
}

NoteGroup::~NoteGroup()
{
    // 析构函数
}

QList<QWidget*> NoteGroup::getElements()
{
    // 直接创建并返回元素列�?
    QList<QWidget*> elements;
    elements.append(new TextNoteDraggable(this));
    elements.append(new TagNoteDraggable(this));
    elements.append(new ImageNoteDraggable(this));
    elements.append(new QrCodeNoteDraggable(this));
    return elements;
}