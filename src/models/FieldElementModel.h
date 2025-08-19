#pragma once

#include "ElementModel.h"
#include <QJsonObject>

class FieldElementModel : public ElementModel
{
    Q_OBJECT

public:
    explicit FieldElementModel(const QJsonObject& fieldConfig, QObject *parent = nullptr);
    virtual ~FieldElementModel();

    // 重写基类方法
    void loadData() override;
    QMimeData* getMimeData() const override;

private:
    QJsonObject m_fieldConfig;
    void parseConfig();
};