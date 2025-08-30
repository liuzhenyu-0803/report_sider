#ifndef INSTRUMENTINFOSUBGROUP_H
#define INSTRUMENTINFOSUBGROUP_H

#include "FieldSubGroup.h"

class InstrumentInfoSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit InstrumentInfoSubGroup(QWidget *parent = nullptr);
    virtual ~InstrumentInfoSubGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // INSTRUMENTINFOSUBGROUP_H
