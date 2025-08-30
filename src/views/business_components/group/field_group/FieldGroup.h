#ifndef FIELDGROUP_H
#define FIELDGROUP_H

#include "views/business_components/group/Group.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"
#include <QVBoxLayout>
#include <QList>

class FieldGroup : public Group
{
    Q_OBJECT

public:
    explicit FieldGroup(QWidget *parent = nullptr);
    virtual ~FieldGroup();

    // 实现基类虚接口函数
    virtual void loadContent() override;
    virtual QList<QWidget*> getContentWidgets() override;
    
    // 子类需要实现的虚函数
    virtual QList<QWidget*> getElements() = 0;
};

#endif // FIELDGROUP_H