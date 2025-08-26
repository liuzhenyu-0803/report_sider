#include "NoteGroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

NoteGroupFrame::NoteGroupFrame(QWidget *parent)
    : UnitGroupFrame(parent)
{
    // 初始化NoteGroupFrame
    // 设置组标题
    setGroupTitle("Note Group");
}

NoteGroupFrame::~NoteGroupFrame()
{
    // 析构函数
}

QList<ElementFrame*> NoteGroupFrame::getElements()
{
    // 直接创建并返回元素列表
    QList<ElementFrame*> elements;
    elements.append(new TextNoteElement(this));
    elements.append(new TagNoteElement(this));
    elements.append(new ImageNoteElement(this));
    elements.append(new QrCodeNoteElement(this));
    return elements;
}