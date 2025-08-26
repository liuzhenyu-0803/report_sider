#ifndef FIELDGROUPFRAME_H
#define FIELDGROUPFRAME_H

#include "GroupFrame.h"
#include "views/business_components/element/FieldElementFrame.h"
#include <QVBoxLayout>
#include <QList>

class FieldGroupFrame : public GroupFrame
{
    Q_OBJECT

public:
    explicit FieldGroupFrame(QWidget *parent = nullptr);
    virtual ~FieldGroupFrame();

    // 实现基类虚接口函数
    virtual void loadElements() override;
};

#endif // FIELDGROUPFRAME_H