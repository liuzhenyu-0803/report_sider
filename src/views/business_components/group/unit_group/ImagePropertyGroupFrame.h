#ifndef IMAGEPROPERTYGROUPFRAME_H
#define IMAGEPROPERTYGROUPFRAME_H

#include "../UnitGroupFrame.h"
#include "views/business_components/element/unit_element/ImageInfoElement.h"
#include "views/business_components/element/unit_element/InstrumentInfoElement.h"
#include <QList>

class ImagePropertyGroupFrame : public UnitGroupFrame
{
    Q_OBJECT

public:
    explicit ImagePropertyGroupFrame(QWidget *parent = nullptr);
    virtual ~ImagePropertyGroupFrame();

    // 实现基类虚接口函数
    virtual QList<ElementFrame*> getElements() override;

private:
    QList<ImageInfoElement *> m_imageInfoElements;
    QList<InstrumentInfoElement *> m_instrumentInfoElements;
};

#endif // IMAGEPROPERTYGROUPFRAME_H