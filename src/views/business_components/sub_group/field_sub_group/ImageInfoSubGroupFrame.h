#ifndef IMAGEINFOSUBGROUPFRAME_H
#define IMAGEINFOSUBGROUPFRAME_H

#include "../FieldSubGroupFrame.h"

class ImageInfoSubGroupFrame : public FieldSubGroupFrame
{
    Q_OBJECT

public:
    explicit ImageInfoSubGroupFrame(QWidget *parent = nullptr);
    virtual ~ImageInfoSubGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // IMAGEINFOSUBGROUPFRAME_H