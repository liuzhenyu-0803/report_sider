#ifndef FIELD_NoteFieldGroup_H
#define FIELD_NoteFieldGroup_H

#include "../FieldGroupFrame.h"

class NoteFieldGroup : public FieldGroupFrame
{
    Q_OBJECT

public:
    explicit NoteFieldGroup(QWidget *parent = nullptr);
    virtual ~NoteFieldGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
};

#endif // NoteFieldGroup_H