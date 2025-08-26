#include "views/business_components/MainWindow.h"

#include "utility/utility.h"

#include "QcApplication.h"

int main(int argc, char *argv[]) {
    MicroUI::QcApplication app(argc, argv);
    app.Initialize();
    app.setDebugTipEnabled(true);
    STYLE_MANAGER->SetColorFilePath(":/colors/blue_light.ini");
    MainWindow w;
    w.show();
    int result = app.exec();
    app.UnInitialize();
    return result;
}