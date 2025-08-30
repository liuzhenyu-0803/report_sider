#ifndef UNIT_NOTEGROUPFRAME_H
#define UNIT_NOTEGROUPFRAME_H

#include "UnitGroup.h"
#include "views/business_components/draggable/unit_draggable/TextNoteDraggable.h"
#include "views/business_components/draggable/unit_draggable/TagNoteDraggable.h"
#include "views/business_components/draggable/unit_draggable/ImageNoteDraggable.h"
#include "views/business_components/draggable/unit_draggable/QrCodeNoteDraggable.h"
#include <QList>

class NoteGroup : public UnitGroup
{
    Q_OBJECT

public:
    explicit NoteGroup(QWidget *parent = nullptr);
    virtual ~NoteGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    QList<TextNoteDraggable *> m_textNoteElements;
    QList<TagNoteDraggable *> m_tagNoteElements;
    QList<ImageNoteDraggable *> m_imageNoteElements;
    QList<QrCodeNoteDraggable *> m_qrCodeNoteElements;
};

#endif // NOTEGROUP_H
