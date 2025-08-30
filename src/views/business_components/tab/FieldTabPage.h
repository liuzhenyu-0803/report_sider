#ifndef FIELDTABPAGE_H
#define FIELDTABPAGE_H

#include "TabPage.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class FieldTabPage : public TabPage
{
    Q_OBJECT

public:
    explicit FieldTabPage(QWidget *parent = nullptr);
    virtual ~FieldTabPage();

private:
    void loadContent();
};

#endif // FIELDTABPAGE_H