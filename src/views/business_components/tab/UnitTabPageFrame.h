#ifndef UNITTABPAGEFRAME_H
#define UNITTABPAGEFRAME_H

#include "TabPageFrame.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class UnitTabPageFrame : public TabPageFrame
{
    Q_OBJECT

public:
    explicit UnitTabPageFrame(QWidget *parent = nullptr);
    virtual ~UnitTabPageFrame();

private:
    void loadContent();
};

#endif // UNITTABPAGEFRAME_H