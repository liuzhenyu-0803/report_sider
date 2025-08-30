#ifndef TEXTNOTESUBGROUP_H
#define TEXTNOTESUBGROUP_H

#include "FieldSubGroup.h"

class TextNoteSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TextNoteSubGroup(QWidget *parent = nullptr);
    virtual ~TextNoteSubGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TEXTNOTESUBGROUP_H
