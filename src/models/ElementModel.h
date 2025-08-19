#pragma once

#include <QObject>
#include <QImage>
#include <QString>
#include <QList>
#include <QUrl>
#include <QMimeData>
#include <QBuffer>
#include <QTextDocument>

// 定义元素类型枚举
enum class ElementType {
    Base,
    Html,
    Image,
    Urls
};

// 定义UI数据结构体
struct UIData {
    QImage icon;
    QString name;
};

struct Data {
    QString html;
    QImage image;
    QString text;
    QList<QUrl> urls;
    QImage icon;     // 新增字段
    QString name;    // 新增字段
};

class ElementModel : public QObject
{
    Q_OBJECT

public:
    explicit ElementModel(ElementType type = ElementType::Base, QObject *parent = nullptr);
    virtual ~ElementModel();

    // 获取元素类型
    ElementType getType() const;
    
    // 实现原来纯虚函数的功能
    virtual void loadData();
    virtual Data getData() const;
    
    // 新增接口，返回UI数据
    virtual UIData getUIData() const;
    
    // 实现原来纯虚函数的功能，用于拖拽功能
    virtual QMimeData* getMimeData() const;

    // 特定类型的方法
    void setHtmlContent(const QString &html);
    void setImagePath(const QString &path);
    void setUrls(const QList<QUrl> &urls);
    
    // 图像加载方法
    void loadImage(const QString &path);

signals:
    // 加载完成信号
    void signalLoadFinished();

protected:
    Data data;
    ElementType m_type;
    
    // 子类特有的成员变量
    QString m_htmlContent;
    QString m_imagePath;
    QList<QUrl> m_urls;
};