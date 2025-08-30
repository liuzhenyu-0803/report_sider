#include "NoteFieldGroup.h"

#include "views/business_components/sub_group/field_sub_group/TextNoteSubGroup.h"
#include "views/business_components/sub_group/field_sub_group/TagNoteSubGroup.h"

NoteFieldGroup::NoteFieldGroup(QWidget *parent)
    : FieldGroup(parent)
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
    TextNoteSubGroup *resultSubGroup = new TextNoteSubGroup(this);
    subGroups.append(resultSubGroup);

    // 创建标签备注子组
    TagNoteSubGroup *parametersSubGroup = new TagNoteSubGroup(this);
    subGroups.append(parametersSubGroup);

    return subGroups;
}