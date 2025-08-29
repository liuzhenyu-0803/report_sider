#ifndef UNIT_NOTEGROUPFRAME_H
#define UNIT_NOTEGROUPFRAME_H

#include "../UnitGroupFrame.h"
#include "views/business_components/element/unit_element/TextNoteElement.h"
#include "views/business_components/element/unit_element/TagNoteElement.h"
#include "views/business_components/element/unit_element/ImageNoteElement.h"
#include "views/business_components/element/unit_element/QrCodeNoteElement.h"
#include <QList>

class NoteGroupFrame : public UnitGroupFrame
{
    Q_OBJECT

public:
    explicit NoteGroupFrame(QWidget *parent = nullptr);
    virtual ~NoteGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    QList<TextNoteElement *> m_textNoteElements;
    QList<TagNoteElement *> m_tagNoteElements;
    QList<ImageNoteElement *> m_imageNoteElements;
    QList<QrCodeNoteElement *> m_qrCodeNoteElements;
};

#endif // NOTEGROUPFRAME_H