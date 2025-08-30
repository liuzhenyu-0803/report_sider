#ifndef IMAGEINFOSUBGROUP_H
#define IMAGEINFOSUBGROUP_H

#include "FieldSubGroup.h"

class ImageInfoSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit ImageInfoSubGroup(QWidget *parent = nullptr);
    virtual ~ImageInfoSubGroup();

    // 实现基类虚接口函�?
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // IMAGEINFOSUBGROUP_H
