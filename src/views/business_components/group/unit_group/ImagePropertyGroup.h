#ifndef UNIT_IMAGEPROPERTYGROUPFRAME_H
#define UNIT_IMAGEPROPERTYGROUPFRAME_H

#include "UnitGroup.h"
#include "views/business_components/draggable/unit_draggable/ImageInfoDraggable.h"
#include "views/business_components/draggable/unit_draggable/InstrumentInfoDraggable.h"
#include "views/business_components/draggable/unit_draggable/GeographicInfoDraggable.h"
#include <QList>

class ImagePropertyGroup : public UnitGroup
{
    Q_OBJECT

public:
    explicit ImagePropertyGroup(QWidget *parent = nullptr);
    virtual ~ImagePropertyGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    QList<ImageInfoDraggable *> m_imageInfoElements;
    QList<InstrumentInfoDraggable *> m_instrumentInfoElements;
    QList<GeographicInfoDraggable *> m_geographicInfoElements;
};

#endif // IMAGEPROPERTYGROUP_H
