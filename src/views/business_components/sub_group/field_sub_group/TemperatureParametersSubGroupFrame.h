#ifndef TEMPERATUREPARAMETERSSUBGROUPFRAME_H
#define TEMPERATUREPARAMETERSSUBGROUPFRAME_H

#include "../FieldSubGroupFrame.h"

class TemperatureParametersSubGroupFrame : public FieldSubGroupFrame
{
    Q_OBJECT

public:
    explicit TemperatureParametersSubGroupFrame(QWidget *parent = nullptr);
    virtual ~TemperatureParametersSubGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TEMPERATUREPARAMETERSSUBGROUPFRAME_H