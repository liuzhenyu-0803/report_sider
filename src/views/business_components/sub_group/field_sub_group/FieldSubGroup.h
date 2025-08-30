#ifndef FIELDSUBGROUP_H
#define FIELDSUBGROUP_H

#include "views/business_components/sub_group/SubGroup.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"
#include <QVBoxLayout>
#include <QList>

class FieldSubGroup : public SubGroup
{
    Q_OBJECT

public:
    explicit FieldSubGroup(QWidget *parent = nullptr);
    virtual ~FieldSubGroup();

    // 实现基类虚接口函�?
    virtual void loadElements() override;
};

#endif // FIELDSUBGROUP_H