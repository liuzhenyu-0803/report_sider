#include "model.h"

Model::Model(QObject *parent)
    : QObject(parent)
{
}

Model::~Model()
{
}

void Model::setThermalImageIndex(int index)
{
    m_thermalImageIndex = index;
    emit signalThermalImageIndexChanged(index);
}

int Model::getThermalImageIndex()
{
    return m_thermalImageIndex;
}
