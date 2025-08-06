#pragma once

#include <QObject>
#include <QMimeData>

class ElementViewModel : public QObject {
    Q_OBJECT

public:
    explicit ElementViewModel(QObject *parent = nullptr);
    virtual ~ElementViewModel();

    // 纯虚函数，子类必须实现
    virtual QMimeData* getMimeData() const = 0;
};