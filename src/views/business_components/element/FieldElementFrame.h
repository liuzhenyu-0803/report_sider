#pragma once

#include "ElementFrame.h"

class FieldElementFrame : public ElementFrame
{
    Q_OBJECT

public:
    explicit FieldElementFrame(QWidget *parent = nullptr);
    virtual ~FieldElementFrame();

protected:
    void loadData() override;

    // 实现父类虚接口：返回拖拽时的 MimeData
    virtual QMimeData* getMimeData() const override;
};