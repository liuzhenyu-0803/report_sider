#include "RuleAreaDraggable.h"
#include "QcGlobalDefine.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

#include <QDebug>

RuleAreaDraggable::RuleAreaDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/rule_area.svg");
    setText("Rule Area");
}

RuleAreaDraggable::~RuleAreaDraggable()
{
}

void RuleAreaDraggable::mousePressEvent(QMouseEvent *event)
{
    QMimeData *mimeData = new QMimeData();
    mimeData->setHtml(MicroUI::GetFileContent("://html/rule_area.html").arg(Model::getInstance()->getThermalImageIndex()));
    setMimeData(mimeData);
}