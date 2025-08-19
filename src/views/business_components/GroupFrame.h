#ifndef GROUPFRAME_H
#define GROUPFRAME_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>

// 前置声明
class GroupModel;
class ElementModel;

class GroupFrame : public QFrame
{
    Q_OBJECT

public:
    explicit GroupFrame(GroupModel* groupModel, QWidget *parent = nullptr);
    virtual ~GroupFrame();

private:
    void setupUI();
    void createElementFrames();
    
    GroupModel* m_groupModel;
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_contentLayout;
    QLabel *m_groupLabel;
};

#endif // GROUPFRAME_H