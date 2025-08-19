#include "views/business_components/MainWindow.h"

#include "utility/utility.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setStyleSheet(getFileContent(":/qss/business.qss"));
    MainWindow w;
    w.show();
    return app.exec();
}