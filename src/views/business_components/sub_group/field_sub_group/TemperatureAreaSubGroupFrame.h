#ifndef TEMPERATUREAREASUBGROUPFRAME_H
#define TEMPERATUREAREASUBGROUPFRAME_H

#include "../FieldSubGroupFrame.h"

class TemperatureAreaSubGroupFrame : public FieldSubGroupFrame
{
    Q_OBJECT

public:
    explicit TemperatureAreaSubGroupFrame(QWidget *parent = nullptr);
    virtual ~TemperatureAreaSubGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TEMPERATUREAREASUBGROUPFRAME_H