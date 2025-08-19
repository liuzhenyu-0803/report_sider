#include "utility.h"

#include <QFile>

QString getFileContent(const QString& filePath) 
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        return "";
    }

    QString content = file.readAll();
    file.close();
    
    return content;
}