#ifndef TAGNOTESUBGROUP_H
#define TAGNOTESUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"

class TagNoteSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TagNoteSubGroup(QWidget *parent = nullptr);
    virtual ~TagNoteSubGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void setDragElementText();
    void setDragElementMimeData();
    
    FieldDraggable *dragElement_1;
    
    QList<QWidget*> m_elements;
};

#endif // TAGNOTESUBGROUP_H
