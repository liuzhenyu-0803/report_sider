#ifndef UNITGROUPFRAME_H
#define UNITGROUPFRAME_H

#include "GroupFrame.h"
#include "views/business_components/element/UnitElement.h"
#include "views/common_components/FlowLayout.h"
#include <QList>

class UnitGroupFrame : public GroupFrame
{
    Q_OBJECT

public:
    explicit UnitGroupFrame(QWidget *parent = nullptr);
    virtual ~UnitGroupFrame();

    // 实现虚接口函数
    virtual void loadData() override;

private:
    QList<UnitElement *> m_unitElements;
};

#endif // UNITGROUPFRAME_H