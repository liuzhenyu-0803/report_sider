#ifndef GEOGRAPHICINFOSUBGROUP_H
#define GEOGRAPHICINFOSUBGROUP_H

#include "FieldSubGroup.h"

class GeographicInfoSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit GeographicInfoSubGroup(QWidget *parent = nullptr);
    virtual ~GeographicInfoSubGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // GEOGRAPHICINFOSUBGROUP_H
