#ifndef GROUPFRAME_H
#define GROUPFRAME_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include <QHBoxLayout>
#include <QPushButton>
#include <QEvent>
#include "views/business_components/element/ElementFrame.h"

// 前置声明
class GroupFrame : public QFrame
{
    Q_OBJECT

public:
    explicit GroupFrame(QWidget *parent = nullptr);
    virtual ~GroupFrame();

    // 虚接口函数
    virtual void loadData() = 0;

protected:
    void setGroupTitle(const QString &title);
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void toggleContent();

private:
    void setupUI();
    
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_titleLayout;
    QLabel *m_groupLabel;
    QPushButton *m_toggleButton;
    bool m_isExpanded;
};

#endif // GROUPFRAME_H