#ifndef SPINBOX_H
#define SPINBOX_H

#include <QSpinBox>
#include <QString>
#include <QProxyStyle>
#include <QPainter>
#include <QStyleOption> // 包含 QStyleOptionSpinBox 以获取更详细的状态
#include <QPainterPath>
#include <QMouseEvent>
#include <QRect>

class SpinBox : public QSpinBox
{
    Q_OBJECT

public:
    explicit SpinBox(QWidget *parent = nullptr);
    virtual ~SpinBox();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void updateImageRects();  // 更新图片区域矩形
    void updateImageAreaStates();  // 更新鼠标在图片区域的状态
    
    // 图片相关常量
    static constexpr int IMAGE_WIDTH = 20;
    static constexpr int IMAGE_HEIGHT = 10;
    static constexpr int HORIZONTAL_MARGIN = 2;
    
    QSize imageSize_;  // 图片大小
    QRect image1Rect_;  // image1区域的矩形
    QRect image2Rect_;  // image2区域的矩形
    bool isInImage1Area_;  // 是否在image1区域
    bool isInImage2Area_;  // 是否在image2区域
};

#endif // SPINBOX_H