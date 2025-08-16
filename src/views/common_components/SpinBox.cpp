#include "SpinBox.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

SpinBox::SpinBox(QWidget *parent)
    : QSpinBox(parent)
{
    loadStyleSheet();
}

SpinBox::~SpinBox()
{
}

void SpinBox::loadStyleSheet()
{
    QFile file(":/qss/SpinBox.qss");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        file.close();
        
        setStyleSheet(styleSheet);
    } else {
        qDebug() << "Failed to load SpinBox.qss";
    }
}