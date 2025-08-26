#ifndef UNITIMAGEGROUPFRAME_H
#define UNITIMAGEGROUPFRAME_H

#include "../UnitGroupFrame.h"
#include "views/business_components/element/unit_element/ThermalImageElement.h"
#include "views/business_components/element/unit_element/VisibleLightElement.h"
#include "views/business_components/element/unit_element/NormalImageElement.h"
#include <QList>

class UnitImageGroupFrame : public UnitGroupFrame
{
    Q_OBJECT

public:
    explicit UnitImageGroupFrame(QWidget *parent = nullptr);
    virtual ~UnitImageGroupFrame();

    // 实现基类虚接口函数
    virtual QList<ElementFrame*> getElements() override;

private:
    QList<ThermalImageElement *> m_thermalImageElements;
    QList<VisibleLightElement *> m_visibleLightElements;
    QList<NormalImageElement *> m_normalImageElements;
};

#endif // UNITIMAGEGROUPFRAME_H