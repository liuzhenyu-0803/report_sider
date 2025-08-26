#ifndef FIELDINFOGROUPFRAME_H
#define FIELDINFOGROUPFRAME_H

#include "../FieldGroupFrame.h"
#include "views/business_components/element/FieldElementFrame.h"
#include <QList>

class FieldInfoGroupFrame : public FieldGroupFrame
{
    Q_OBJECT

public:
    explicit FieldInfoGroupFrame(QWidget *parent = nullptr);
    virtual ~FieldInfoGroupFrame();

    // 实现基类虚接口函数
    virtual QList<ElementFrame*> getElements() override;

private:
    QList<FieldElementFrame *> m_fieldElements;
};

#endif // FIELDINFOGROUPFRAME_H