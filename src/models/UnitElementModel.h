#pragma once

#include "ElementModel.h"
#include <QJsonObject>

class UnitElementModel : public ElementModel
{
    Q_OBJECT

public:
    explicit UnitElementModel(const QJsonObject& elementConfig, QObject *parent = nullptr);
    virtual ~UnitElementModel();

    // 重写基类方法
    void loadData() override;
    QMimeData* getMimeData() const override;

private:
    QJsonObject m_elementConfig;
    void parseConfig();
};