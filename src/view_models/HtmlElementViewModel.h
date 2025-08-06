#pragma once

#include "ElementViewModel.h"
#include <QString>

// 包含HtmlElementModel头文件
#include "../models/HtmlElementModel.h"

class HtmlElementViewModel : public ElementViewModel {
    Q_OBJECT

public:
    explicit HtmlElementViewModel(QObject *parent = nullptr);
    virtual ~HtmlElementViewModel();

    // 实现基类的纯虚函数
    virtual QMimeData* getMimeData() const override;
    
    // 添加公共方法获取HtmlElementModel实例
    HtmlElementModel* getHtmlElementModel() const;

protected:
    HtmlElementModel *m_htmlElementModel;
    QString m_htmlContent;
};