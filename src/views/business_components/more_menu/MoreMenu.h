#ifndef MORE_MENU_H
#define MORE_MENU_H

#include "QcFrame.h"

#include "QcLabel.h"

#include <QBoxLayout>

class MoreMenu : public MicroUI::QcFrame
{
    Q_OBJECT

public:
    explicit MoreMenu(QWidget *parent = nullptr);
    ~MoreMenu();

    void setTitle(const QString &title);

    QFrame *getContentFrame();
    QLayout *getContentLayout();

private:
    void setupUI();

    MicroUI::QcLabel *m_titleLabel = nullptr;
    QFrame *m_contentFrame = nullptr;
};

#endif // MORE_MENU_H