#ifndef IMAGE_CREATOR_H
#define IMAGE_CREATOR_H

#include <QWidget>

class ImageCreator : public QWidget
{
    Q_OBJECT

public:
    explicit ImageCreator(QWidget *parent = nullptr);
    ~ImageCreator();

    void setIconPath(const QString &path);
    void setText(const QString &text);
    void setBackgroundColorParams(const QString &colorParams);
    void setMetaData(const QString &metaData);
    void createImage(const QString &outputPath);

private:
    QString m_iconPath;
    QString m_text;
    QString m_backgroundColorParams;
    QString m_metaData;
};

#endif // IMAGE_CREATOR_H