#pragma once

#include "ElementModel.h"
#include <QString>
#include <QUrl>
#include <QList>

class UrlsElementModel : public ElementModel
{
    Q_OBJECT

public:
    explicit UrlsElementModel(QObject *parent = nullptr);
    virtual ~UrlsElementModel();

    // 实现基类的纯虚函数
    virtual void loadData() override;
    virtual Data getData() const override;

signals:
    // 加载完成信号
    void signalLoadFinished();

protected:
    QList<QUrl> m_urls;
};