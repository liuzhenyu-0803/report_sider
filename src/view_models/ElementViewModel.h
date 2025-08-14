#pragma once

#include <QObject>
#include <QMimeData>
#include <QImage>
#include <QString>

// 前向声明
class ElementModel;

// 定义UI数据结构体
struct UIData {
    QImage icon;
    QString name;
};

class ElementViewModel : public QObject {
    Q_OBJECT

public:
    explicit ElementViewModel(QObject *parent = nullptr);
    virtual ~ElementViewModel();

    // 纯虚函数，子类必须实现
    virtual QMimeData* getMimeData() const = 0;
    
    // 新增接口，返回UI数据，提供默认实现
    virtual UIData getUIData() const;
 
protected:
    ElementModel* m_elementModel;
};