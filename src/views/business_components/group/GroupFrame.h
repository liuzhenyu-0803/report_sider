#ifndef GROUPFRAME_H
#define GROUPFRAME_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QEvent>

#include "QcLabel.h"
#include "views/business_components/element/ElementFrame.h"

// 前置声明
class GroupFrame : public QFrame
{
    Q_OBJECT

public:
    explicit GroupFrame(QWidget *parent = nullptr);
    virtual ~GroupFrame();

    // 虚接口函数
    virtual void loadElements() = 0;
    virtual QList<ElementFrame*> getElements() = 0;

protected:
    void setGroupTitle(const QString &title);
    bool eventFilter(QObject *obj, QEvent *event) override;
    
    // 提供给子类访问的contentWidget
    QWidget* getContentWidget() const { return m_contentWidget; }

private slots:
    void toggleContent();

private:
    void setupUI();
    
    QVBoxLayout *m_mainLayout = nullptr;
    QHBoxLayout *m_titleLayout = nullptr;
    QLabel *m_groupLabel = nullptr;
    MicroUI::QcLabel *m_iconLabel = nullptr;
    QWidget *m_contentWidget = nullptr;  // 内容容器
    bool m_isExpanded = false;
};

#endif // GROUPFRAME_H