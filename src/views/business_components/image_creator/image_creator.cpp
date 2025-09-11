#include "image_creator.h"

#include "QcStyleManager.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QImageWriter>
#include <QPainter>
#include <QImageReader>

#include <QDebug>

ImageCreator::ImageCreator(QWidget *parent)
    : QWidget(parent)
{
    // Setup UI
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel(this);
    layout->addWidget(label);
    setLayout(layout);
}

ImageCreator::~ImageCreator()
{

}

void ImageCreator::setIconPath(const QString &path)
{
    m_iconPath = path;
}

void ImageCreator::setText(const QString &text)
{
    m_text = text;
}

void ImageCreator::setBorderColorParams(const QString &color)
{
    m_borderColorParams = color;
}

void ImageCreator::setBackgroundColorParams(const QString &colorParams)
{
    m_backgroundColorParams = colorParams;
}

void ImageCreator::createImage(const QString &outputPath)
{
    // 创建QImage 然后绘制一个圆角矩形 左上角绘制m_iconPath图标 然后是文字 最后保存
    QImage image(260, 200, QImage::Format_ARGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.save();
    painter.setPen(GET_COLOR(m_borderColorParams));
    painter.setBrush(GET_COLOR(m_backgroundColorParams));
    painter.drawRoundedRect(0, 0, image.width(), image.height(), 10, 10);
    painter.restore();

    auto iconRect = QRect(10, 10, 24, 24);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.drawPixmap(iconRect, QPixmap(m_iconPath));
    painter.restore();

    painter.save();
    painter.drawText(QRect(iconRect.right() + 10, iconRect.top(), width(), iconRect.height()), Qt::AlignLeft | Qt::AlignVCenter, m_text);
    qDebug() << m_text;
    painter.restore();

    painter.save();
    painter.setPen(GET_COLOR("#ACACAC"));
    painter.drawText(QRect(iconRect.left(), iconRect.bottom() + 5, width(), iconRect.height()), Qt::AlignLeft | Qt::AlignVCenter, m_metaData);
    qDebug() << m_metaData;
    painter.restore();

    image.save(outputPath);

    QImageWriter writer(outputPath);
    writer.setText("Description", m_metaData);
    writer.write(image);

    QImageReader reader(outputPath);
    qDebug() << reader.text("Description");
}

void ImageCreator::setMetaData(const QString &metaData)
{
    m_metaData = metaData;
}