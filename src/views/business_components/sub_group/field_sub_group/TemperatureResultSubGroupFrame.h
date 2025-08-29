#ifndef TEMPERATURERESULTSUBGROUPFRAME_H
#define TEMPERATURERESULTSUBGROUPFRAME_H

#include "../FieldSubGroupFrame.h"

class TemperatureResultSubGroupFrame : public FieldSubGroupFrame
{
    Q_OBJECT

public:
    explicit TemperatureResultSubGroupFrame(QWidget *parent = nullptr);
    virtual ~TemperatureResultSubGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TEMPERATURERESULTSUBGROUPFRAME_H