#include "Model.h"

Model::Model(QObject *parent)
    : QObject(parent) {
}

Model::~Model() {
    clearGroupModels();
}

QList<GroupModel*> Model::getGroupModels() const {
    return m_groupModels;
}

void Model::clearGroupModels() {
    qDeleteAll(m_groupModels);
    m_groupModels.clear();
}