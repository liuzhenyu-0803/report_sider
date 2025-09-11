#include "NoteFieldGroup.h"

#include "views/business_components/sub_group/field_sub_group/NoteInfoSubGroup.h"
#include "views/business_components/sub_group/field_sub_group/TagNoteSubGroup.h"

NoteFieldGroup::NoteFieldGroup(QWidget *parent)
    : FieldGroup(parent)
{
    setGroupTitle(tr("RemarkCellName"));
}

NoteFieldGroup::~NoteFieldGroup()
{
}

QList<QWidget*> NoteFieldGroup::getElements()
{
    QList<QWidget*> subGroups;
    // 创建备注信息子组
    NoteInfoGroup *resultSubGroup = new NoteInfoGroup(this);
    subGroups.append(resultSubGroup);

    // 创建标签备注子组
    TagNoteSubGroup *parametersSubGroup = new TagNoteSubGroup(this);
    subGroups.append(parametersSubGroup);

    return subGroups;
}