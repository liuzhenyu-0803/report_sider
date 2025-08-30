#ifndef FIELD_ImagePropertyFieldGroup_H
#define FIELD_ImagePropertyFieldGroup_H

#include "FieldGroup.h"

class ImagePropertyFieldGroup : public FieldGroup
{
    Q_OBJECT

public:
    explicit ImagePropertyFieldGroup(QWidget *parent = nullptr);
    virtual ~ImagePropertyFieldGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createSubGroups();
    
    QList<QWidget*> m_subGroups;
};

#endif // IMAGEPROPERTYGROUP_H