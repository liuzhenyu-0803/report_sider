#ifndef NOTEINFO_H
#define NOTEINFO_H

#include "FieldSubGroup.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"

class NoteInfoGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit NoteInfoGroup(QWidget *parent = nullptr);
    virtual ~NoteInfoGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void setDragElement1Text();
    void setDragElement2Text();
    void setDragElement3Text();

    void setDragElement1MimeData();
    void setDragElement2MimeData();
    void setDragElement3MimeData();

    QList<QWidget*> m_elements;
    
    FieldDraggable *dragElement_1;
    FieldDraggable *dragElement_2;
    FieldDraggable *dragElement_3;
};

#endif // NOTEINFO_H
