#ifndef INSTRUMENTINFOSUBGROUPFRAME_H
#define INSTRUMENTINFOSUBGROUPFRAME_H

#include "../FieldSubGroupFrame.h"

class InstrumentInfoSubGroupFrame : public FieldSubGroupFrame
{
    Q_OBJECT

public:
    explicit InstrumentInfoSubGroupFrame(QWidget *parent = nullptr);
    virtual ~InstrumentInfoSubGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // INSTRUMENTINFOSUBGROUPFRAME_H