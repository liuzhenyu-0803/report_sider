#ifndef GROUP_H
#define GROUP_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QEvent>

#include "QcLabel.h"
#include "views/business_components/draggable/Draggable.h"

// 前置声明
class Group : public QFrame
{
    Q_OBJECT

public:
    explicit Group(QWidget *parent = nullptr);
    virtual ~Group();

protected:
    void setGroupTitle(const QString &title);    
    QWidget* getContentWidget() const;

    virtual void loadContent() = 0;
    virtual QList<QWidget*> getContentWidgets() = 0;
    
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void toggleContent();

private:
    void setupUI();
    
    QVBoxLayout *m_mainLayout = nullptr;
    QHBoxLayout *m_titleLayout = nullptr;
    MicroUI::QcLabel *m_groupLabel = nullptr;
    MicroUI::QcLabel *m_iconLabel = nullptr;
    QWidget *m_contentWidget = nullptr;  // 内容容器
    bool m_isExpanded = true;
};

#endif // GROUP_H