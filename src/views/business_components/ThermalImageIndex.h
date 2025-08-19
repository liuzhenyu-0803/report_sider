#ifndef THERMALIMAGEINDEX_H
#define THERMALIMAGEINDEX_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../common_components/SpinBox.h"
#include "../common_components/InnerTip.h"

class ThermalImageIndex : public QWidget
{
    Q_OBJECT

public:
    explicit ThermalImageIndex(QWidget *parent = nullptr);
    virtual ~ThermalImageIndex();

    int getIndex() const;

private:
    QLabel *label = nullptr;
    SpinBox *spinBox = nullptr;
    QVBoxLayout *mainLayout = nullptr;
};

#endif // THERMALIMAGEINDEX_H