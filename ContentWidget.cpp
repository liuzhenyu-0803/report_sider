#include "ContentWidget.h"

ContentWidget::ContentWidget(QWidget *parent)
    : QWidget(parent) {
    setupUI();
}

ContentWidget::~ContentWidget() = default;

void ContentWidget::setupUI() {
    setStyleSheet("background-color: #f0f0f0;");
}