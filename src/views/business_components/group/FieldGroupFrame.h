#ifndef FIELDGROUPFRAME_H
#define FIELDGROUPFRAME_H

#include "GroupFrame.h"
#include "views/business_components/element/FieldElement.h"
#include <QVBoxLayout>
#include <QList>

class FieldGroupFrame : public GroupFrame
{
    Q_OBJECT

public:
    explicit FieldGroupFrame(QWidget *parent = nullptr);
    virtual ~FieldGroupFrame();

    // 实现虚接口函数
    virtual void loadData() override;

private:
    QList<FieldElement *> m_fieldElements;
};

#endif // FIELDGROUPFRAME_H