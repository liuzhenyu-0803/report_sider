#include "NoteFieldGroup.h"

#include "views/business_components/sub_group/field_sub_group/TextNoteSubGroup.h"
#include "views/business_components/sub_group/field_sub_group/TagNoteSubGroup.h"
#include "views/business_components/sub_group/field_sub_group/QrCodeNoteSubGroup.h"

NoteFieldGroup::NoteFieldGroup(QWidget *parent)
    : FieldGroup(parent)
{
    setGroupTitle(tr("note"));
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

    // 创建二维码备注子组
    QrCodeNoteSubGroup *qrCodeSubGroup = new QrCodeNoteSubGroup(this);
    subGroups.append(qrCodeSubGroup);

    return subGroups;
}