#include "NoteFieldGroup.h"

#include "views/business_components/sub_group/field_sub_group/TextNoteSubGroupFrame.h"
#include "views/business_components/sub_group/field_sub_group/TagNoteSubGroupFrame.h"

NoteFieldGroup::NoteFieldGroup(QWidget *parent)
    : FieldGroupFrame(parent)
{
    setGroupTitle("备注");
}

NoteFieldGroup::~NoteFieldGroup()
{
}

QList<QWidget*> NoteFieldGroup::getElements()
{
    QList<QWidget*> subGroups;
    // 创建文本备注子组
    TextNoteSubGroupFrame *resultSubGroup = new TextNoteSubGroupFrame(this);
    subGroups.append(resultSubGroup);

    // 创建标签备注子组
    TagNoteSubGroupFrame *parametersSubGroup = new TagNoteSubGroupFrame(this);
    subGroups.append(parametersSubGroup);

    return subGroups;
}