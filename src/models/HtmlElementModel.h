#pragma once

#include "ElementModel.h"
#include <QString>

class HtmlElementModel : public ElementModel
{
    Q_OBJECT

public:
    explicit HtmlElementModel(QObject *parent = nullptr);
    virtual ~HtmlElementModel();

    // 实现基类的纯虚函数
    virtual void loadData() override;
    virtual Data getData() const override;

signals:
    // 加载完成信号
    void signalLoadFinished();

protected:
    QString m_htmlContent;
};