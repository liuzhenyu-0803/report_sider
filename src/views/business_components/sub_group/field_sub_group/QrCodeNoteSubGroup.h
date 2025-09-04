#ifndef QRCODENOTESUBGROUP_H
#define QRCODENOTESUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"

class QrCodeNoteSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit QrCodeNoteSubGroup(QWidget *parent = nullptr);
    virtual ~QrCodeNoteSubGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void setDragElementText();
    void setDragElementMimeData();
    
    QList<QWidget*> m_elements;
    
    FieldDraggable *dragElement_1;
};

#endif // QRCODENOTESUBGROUP_H