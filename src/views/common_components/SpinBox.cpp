#include "SpinBox.h"

#include "QcStyleManager.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

SpinBox::SpinBox(QWidget *parent)
    : QSpinBox(parent)
{
    REGISTER_QSS(this, ":/qss/SpinBox.qss");
}

SpinBox::~SpinBox()
{
}