#ifndef GEOGRAPHICINFOSUBGROUP_H
#define GEOGRAPHICINFOSUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"

class GeographicInfoSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit GeographicInfoSubGroup(QWidget *parent = nullptr);
    virtual ~GeographicInfoSubGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void setDraggable1Text();
    void setDraggable2Text();
    void setDraggable1MimeData();
    void setDraggable2MimeData();
    
    QList<QWidget*> m_elements;
    
    FieldDraggable *dragElement1;  // GPS
    FieldDraggable *dragElement2;  // 电子罗盘
};

#endif // GEOGRAPHICINFOSUBGROUP_H
