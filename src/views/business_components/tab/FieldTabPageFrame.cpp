#include "FieldTabPageFrame.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "views/business_components/group/GroupFrame.h"

FieldTabPageFrame::FieldTabPageFrame(QWidget *parent)
    : TabPageFrame(parent)
{
    loadContent();
}

FieldTabPageFrame::~FieldTabPageFrame()
{
}

void FieldTabPageFrame::loadContent()
{
    
}