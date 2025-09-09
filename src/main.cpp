#include "views/business_components/MainWindow.h"

#include "QcApplication.h"

#include <QDebug>
#include <QTranslator>
#include <QDir>

int main(int argc, char *argv[])
{
    MicroUI::QcApplication app(argc, argv);
    
    // 加载翻译文件
    QTranslator translator;
    QString translationFile = qApp->applicationDirPath() + "/translations/zh_CN.qm";
    if (translator.load(translationFile)) {
        app.installTranslator(&translator);
        qDebug() << "成功加载翻译文件:" << translationFile;
    } else {
        qDebug() << "无法加载翻译文件:" << translationFile;
    }
    
    app.Initialize();
    app.setDebugTipEnabled(true);
    
    STYLE_MANAGER->SetColorFilePath(":/colors/blue_light.ini");
    
    MainWindow w;
    w.show();
    
    app.exec();
    
    app.UnInitialize();
    
    return 0;
}