#ifndef TABPAGEFRAME_H
#define TABPAGEFRAME_H

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
class GroupFrame;

class TabPageFrame : public QFrame
{
    Q_OBJECT

public:
    explicit TabPageFrame(QWidget *parent = nullptr);
    virtual ~TabPageFrame();

protected:
    QWidget *m_contentWidget = nullptr;

private:
    void setupUI();

    QVBoxLayout *m_mainLayout = nullptr;
    QVBoxLayout *m_contentLayout = nullptr;
    QScrollArea *m_scrollArea = nullptr;
};
#endif // TABPAGEFRAME_H