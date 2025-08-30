#ifndef UNITTABPAGE_H
#define UNITTABPAGE_H

#include "TabPage.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class UnitTabPage : public TabPage
{
    Q_OBJECT

public:
    explicit UnitTabPage(QWidget *parent = nullptr);
    virtual ~UnitTabPage();

private:
    void loadContent() override;
};

#endif // UNITTABPAGE_H