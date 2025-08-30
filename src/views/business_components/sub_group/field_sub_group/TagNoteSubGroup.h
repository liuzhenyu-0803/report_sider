#ifndef TAGNOTESUBGROUP_H
#define TAGNOTESUBGROUP_H

#include "FieldSubGroup.h"

class TagNoteSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TagNoteSubGroup(QWidget *parent = nullptr);
    virtual ~TagNoteSubGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TAGNOTESUBGROUP_H
