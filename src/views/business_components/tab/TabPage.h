#ifndef TABPAGE_H
#define TABPAGE_H

#include <QFrame>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QString>
#include "global/global.h"

// 前置声明
class Model;
class GroupModel;
class ElementModel;
class UnitElementModel;
class Group;

class TabPage : public QFrame
{
    Q_OBJECT

public:
    explicit TabPage(QWidget *parent = nullptr);
    virtual ~TabPage();

protected:
    virtual void loadContent() = 0;

    QWidget *m_contentWidget = nullptr;

private:
    void setupUI();

    QVBoxLayout *m_mainLayout = nullptr;
    QVBoxLayout *m_contentLayout = nullptr;
    QScrollArea *m_scrollArea = nullptr;
};
#endif // TABPAGE_H