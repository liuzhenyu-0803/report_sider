#ifndef GEOGRAPHICINFOSUBGROUPFRAME_H
#define GEOGRAPHICINFOSUBGROUPFRAME_H

#include "../FieldSubGroupFrame.h"

class GeographicInfoSubGroupFrame : public FieldSubGroupFrame
{
    Q_OBJECT

public:
    explicit GeographicInfoSubGroupFrame(QWidget *parent = nullptr);
    virtual ~GeographicInfoSubGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // GEOGRAPHICINFOSUBGROUPFRAME_H