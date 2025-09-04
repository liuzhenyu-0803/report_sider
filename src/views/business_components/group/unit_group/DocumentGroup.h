#ifndef UNIT_DOCUMENTGROUP_H
#define UNIT_DOCUMENTGROUP_H

#include "UnitGroup.h"
#include "views/business_components/draggable/unit_draggable/SummaryTableDraggable.h"
#include "views/business_components/draggable/unit_draggable/CoverTableDraggable.h"
#include <QList>

class DocumentGroup : public UnitGroup
{
    Q_OBJECT

public:
    explicit DocumentGroup(QWidget *parent = nullptr);
    virtual ~DocumentGroup();

protected:
    QList<QWidget*> getElements() override;

private:
    QList<SummaryTableDraggable *> m_summaryTableElements;
    QList<CoverTableDraggable *> m_coverTableElements;
};

#endif // DOCUMENTGROUP_H