#ifndef IMAGEINFOSUBGROUP_H
#define IMAGEINFOSUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"

class ImageInfoSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit ImageInfoSubGroup(QWidget *parent = nullptr);
    virtual ~ImageInfoSubGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void setDragElement1Text();
    void setDragElement2Text();
    void setDragElement3Text();
    void setDragElement4Text();
    void setDragElement5Text();
    void setDragElement1MimeData();
    void setDragElement2MimeData();
    void setDragElement3MimeData();
    void setDragElement4MimeData();
    void setDragElement5MimeData();
    
    QList<QWidget*> m_elements;
    
    FieldDraggable *dragElement1;  // image name
    FieldDraggable *dragElement2;  // detector resolution
    FieldDraggable *dragElement3;  // image size
    FieldDraggable *dragElement4;  // shooting time
    FieldDraggable *dragElement5;  // save path
};

#endif // IMAGEINFOSUBGROUP_H
