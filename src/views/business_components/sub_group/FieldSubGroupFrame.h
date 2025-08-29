#ifndef FIELDSUBGROUPFRAME_H
#define FIELDSUBGROUPFRAME_H

#include "SubGroupFrame.h"
#include "views/business_components/element/FieldDraggableElement.h"
#include <QVBoxLayout>
#include <QList>

class FieldSubGroupFrame : public SubGroupFrame
{
    Q_OBJECT

public:
    explicit FieldSubGroupFrame(QWidget *parent = nullptr);
    virtual ~FieldSubGroupFrame();

    // 实现基类虚接口函数
    virtual void loadElements() override;
};

#endif // FIELDSUBGROUPFRAME_H