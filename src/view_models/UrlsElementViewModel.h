#pragma once

#include "ElementViewModel.h"
#include <QString>
#include <QList>
#include <QUrl>

// 包含UrlsElementModel头文件
#include "../models/UrlsElementModel.h"

class UrlsElementViewModel : public ElementViewModel {
    Q_OBJECT

public:
    explicit UrlsElementViewModel(QObject *parent = nullptr);
    virtual ~UrlsElementViewModel();

    // 实现基类的纯虚函数
    virtual QMimeData* getMimeData() const override;
    
    // 添加公共方法获取UrlsElementModel实例
    UrlsElementModel* getUrlsElementModel() const;

protected:
    UrlsElementModel *m_urlsElementModel;
    QList<QUrl> m_urls;
};