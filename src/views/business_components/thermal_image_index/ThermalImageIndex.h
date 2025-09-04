#ifndef THERMALIMAGEINDEX_H
#define THERMALIMAGEINDEX_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "views/common_components/SpinBox.h"
#include "views/common_components/InnerTip.h"
#include "QcLabel.h"

class ThermalImageIndex : public QWidget
{
    Q_OBJECT

public:
    explicit ThermalImageIndex(QWidget *parent = nullptr);
    virtual ~ThermalImageIndex();

    int getIndex() const;

private:
    MicroUI::QcLabel *label = nullptr;
    SpinBox *spinBox = nullptr;
    QVBoxLayout *mainLayout = nullptr;
};

#endif // THERMALIMAGEINDEX_H