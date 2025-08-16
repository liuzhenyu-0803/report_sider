#include "ImageElement.h"
#include <QPainter>
#include <QStyleOption>
#include "../../../view_models/ImageElementViewModel.h"

ImageElement::ImageElement(ImageElementViewModel *viewModel, QWidget *parent)
    : Element(viewModel, parent) {
    // 不再在构造函数中获取图像数据
}

ImageElement::~ImageElement() = default;

void ImageElement::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    
    // 先绘制红色背景
    p.setBrush(Qt::red);
    p.drawRect(rect());
    
    // 从ViewModel中获取图像数据
    ImageElementViewModel *imageViewModel = dynamic_cast<ImageElementViewModel*>(m_viewModel);
    if (imageViewModel) {
        // 通过ViewModel获取ImageElementModel，然后获取数据
        Data data = imageViewModel->getImageElementModel()->getData();
        
        // 如果有图像则绘制图像
        if (!data.image.isNull()) {
            // 按比例缩放图像以适应元素大小
            QPixmap pixmap = QPixmap::fromImage(data.image.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            p.drawPixmap((width() - pixmap.width()) / 2, (height() - pixmap.height()) / 2, pixmap);
        }
    }
}