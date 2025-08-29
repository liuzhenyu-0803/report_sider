#include "SpinBox.h"

#include "QcStyleManager.h"

#include <QFile>
#include <QTextStream>
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>
#include <QLineEdit>
#include <QCursor>

SpinBox::SpinBox(QWidget *parent)
    : QSpinBox(parent), imageSize_(IMAGE_WIDTH, IMAGE_HEIGHT), isInImage1Area_(false), isInImage2Area_(false)
{
    setFixedHeight(28);
    REGISTER_QSS(this, ":/qss/SpinBox.qss");
    
    // 启用鼠标追踪
    setMouseTracking(true);
    
    // 初始化计算图片区域
    updateImageRects();

    lineEdit()->installEventFilter(this);
}

SpinBox::~SpinBox()
{

}

bool SpinBox::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == lineEdit()) 
    {
        if (event->type() == QEvent::MouseMove) 
        {
            updateImageAreaStates();
        }
    }

    return QSpinBox::eventFilter(obj, event);
}

void SpinBox::paintEvent(QPaintEvent *event)
{
    QSpinBox::paintEvent(event);

    QPainter painter(this);

    MicroUI::ImageParams imageParams;
    imageParams.size_ = imageSize_;

    // 绘制 image1 (上箭头)
    imageParams.file_path_ = ":/images/spin_up.svg";
    if (isInImage1Area_) {
        imageParams.color_replace_hash_ = {{"#00FF00", "#CFCFCF"}, {"#FF0000", "#000000, 0.6"}};
    } else {
        imageParams.color_replace_hash_ = {{"#00FF00", "#CFCFCF, 0"}, {"#FF0000", "#000000, 0.6"}};
    }
    auto image1 = GET_IMAGE(imageParams);

    // 绘制 image2 (下箭头)
    imageParams.file_path_ = ":/images/spin_down.svg";
    if (isInImage2Area_) {
        imageParams.color_replace_hash_ = {{"#00FF00", "#CFCFCF"}, {"#FF0000", "#000000, 0.6"}};
    } else {
        imageParams.color_replace_hash_ = {{"#00FF00", "#CFCFCF, 0"}, {"#FF0000", "#000000, 0.6"}};
    }
    auto image2 = GET_IMAGE(imageParams);

    painter.drawImage(image1Rect_.x(), image1Rect_.y(), image1);
    painter.drawImage(image2Rect_.x(), image2Rect_.y(), image2);
}

void SpinBox::mouseMoveEvent(QMouseEvent *event)
{
    QSpinBox::mouseMoveEvent(event);
    updateImageAreaStates();
}

void SpinBox::resizeEvent(QResizeEvent *event)
{
    QSpinBox::resizeEvent(event);
    updateImageRects();
}

void SpinBox::updateImageRects()
{
    // 计算image1位置和区域 (上箭头)
    int image1X = width() - IMAGE_WIDTH - HORIZONTAL_MARGIN - 1;
    int image1Y = height() / 2 - IMAGE_HEIGHT;
    image1Rect_ = QRect(image1X, image1Y, IMAGE_WIDTH, IMAGE_HEIGHT);
    
    // 计算image2位置和区域 (下箭头)
    int image2X = width() - IMAGE_WIDTH - HORIZONTAL_MARGIN - 1;
    int image2Y = height() / 2;
    image2Rect_ = QRect(image2X, image2Y, IMAGE_WIDTH, IMAGE_HEIGHT);
}

void SpinBox::updateImageAreaStates()
{
    // 获取全局鼠标位置并转换为控件内坐标
    QPoint globalPos = QCursor::pos();
    QPoint localPos = mapFromGlobal(globalPos);
    
    // 检查鼠标是否在image1区域
    isInImage1Area_ = image1Rect_.contains(localPos);
    
    // 检查鼠标是否在image2区域
    isInImage2Area_ = image2Rect_.contains(localPos);

    update();
}
