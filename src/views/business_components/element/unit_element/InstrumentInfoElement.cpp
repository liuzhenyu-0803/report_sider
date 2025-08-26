#include "InstrumentInfoElement.h"
#include <QMimeData>
#include <QIcon>

InstrumentInfoElement::InstrumentInfoElement(QWidget *parent)
    : UnitElementFrame(parent)
{
}

InstrumentInfoElement::~InstrumentInfoElement()
{
}

QString InstrumentInfoElement::getIcon() const
{
    return ":/images/instrument_info.svg";
}

QString InstrumentInfoElement::getText() const
{
    return "Instrument Info";
}

QMimeData* InstrumentInfoElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("InstrumentInfoElement");
    mimeData->setData("application/x-instrumentinfo", QByteArray());
    
    return mimeData;
}