#ifndef INSTRUMENTINFOSUBGROUP_H
#define INSTRUMENTINFOSUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"

class InstrumentInfoSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit InstrumentInfoSubGroup(QWidget *parent = nullptr);
    virtual ~InstrumentInfoSubGroup();

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
    
    FieldDraggable *dragElement1;  // Device Model
    FieldDraggable *dragElement2;  // Device Serial
    FieldDraggable *dragElement3;  // Lens Magnification
};

#endif // INSTRUMENTINFOSUBGROUP_H
