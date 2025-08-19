#ifndef INNERTIP_H
#define INNERTIP_H

#include <QFrame>
#include <QLabel>
#include <QTextBrowser>
#include <QHBoxLayout>
#include "utility/utility.h"

class InnerTip : public QFrame
{
    Q_OBJECT

public:
    // 样式类型枚举
    enum StyleType {
        Brand,  // 品牌样式（默认样式）
        Gray    // 灰色样式（用于ThermalImageIndex中的tipLabel原有样式）
    };
    Q_ENUM(StyleType)

    explicit InnerTip(QWidget *parent = nullptr);
    virtual ~InnerTip();

    // 对外提供的接口，用于设置文本
    void setText(const QString &text);
    
    // 设置样式类型
    void setStyleType(StyleType styleType);
    
    // 设置是否显示图标
    void setShowIcon(bool show);

private:
    void setupUI();
    void updateStyle();  // 更新样式
    
    StyleType m_styleType;  // 当前样式类型
    bool m_showIcon;           // 是否显示图标
     
    QFrame *m_innerFrame;      // 新增的内部容器
    QLabel *m_iconLabel;
    QTextBrowser *m_textBrowser;
    QHBoxLayout *m_mainLayout;
};

#endif // INNERTIP_H