#ifndef FIELDTABPAGEFRAME_H
#define FIELDTABPAGEFRAME_H

#include "TabPageFrame.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class FieldTabPageFrame : public TabPageFrame
{
    Q_OBJECT

public:
    explicit FieldTabPageFrame(QWidget *parent = nullptr);
    virtual ~FieldTabPageFrame();

private:
    void loadContent();
};

#endif // FIELDTABPAGEFRAME_H