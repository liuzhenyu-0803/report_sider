#include "views/business_components/MainWindow.h"

#include "QcApplication.h"

#include <QDebug>

int main(int argc, char *argv[]) 
{
    MicroUI::QcApplication app(argc, argv);
    
    app.Initialize();
    app.setDebugTipEnabled(true);
    
    STYLE_MANAGER->SetColorFilePath(":/colors/blue_light.ini");
    
    MainWindow w;
    w.show();
    
    app.exec();
    
    app.UnInitialize();
    
    return 0;
}