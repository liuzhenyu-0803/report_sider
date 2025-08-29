#include "ImageInfoSubGroupFrame.h"
#include "views/business_components/element/unit_element/ImageInfoElement.h"
#include "views/business_components/title_combine_widget/ParameterTitleSelector.h"

ImageInfoSubGroupFrame::ImageInfoSubGroupFrame(QWidget *parent)
    : FieldSubGroupFrame(parent)
{
    setGroupTitle("图片信息");
    createElements();
}

ImageInfoSubGroupFrame::~ImageInfoSubGroupFrame()
{
    
}

void ImageInfoSubGroupFrame::createElements()
{
    auto contentWidget = new QWidget(this);
    auto contentWidgetLayout = new QVBoxLayout(contentWidget);
    contentWidgetLayout->setContentsMargins(0, 5, 10, 10);
    contentWidgetLayout->setSpacing(10);

    auto dragElement1 = new FieldDraggableElement(this);
    dragElement1->setCustomData("图片名称");
    auto mimeData = new QMimeData();
    mimeData->setText("图片名称");
    dragElement1->setMimeData(mimeData);
    contentWidgetLayout->addWidget(dragElement1);

    auto dragElement2 = new FieldDraggableElement(this);
    dragElement2->setCustomData("探测器分辨率");
    auto mimeData2 = new QMimeData();
    mimeData2->setText("探测器分辨率");
    dragElement2->setMimeData(mimeData2);
    contentWidgetLayout->addWidget(dragElement2);

    auto dragElement3 = new FieldDraggableElement(this);
    dragElement3->setCustomData("图片大小");
    auto mimeData3 = new QMimeData();
    mimeData3->setText("图片大小");
    dragElement3->setMimeData(mimeData3);
    contentWidgetLayout->addWidget(dragElement3);

    auto dragElement4 = new FieldDraggableElement(this);
    dragElement4->setCustomData("拍摄时间");
    auto mimeData4 = new QMimeData();
    mimeData4->setText("拍摄时间");
    dragElement4->setMimeData(mimeData4);
    contentWidgetLayout->addWidget(dragElement4);

    auto dragElement5 = new FieldDraggableElement(this);
    dragElement5->setCustomData("保存路径");
    auto mimeData5 = new QMimeData();
    mimeData5->setText("保存路径");
    dragElement5->setMimeData(mimeData5);
    contentWidgetLayout->addWidget(dragElement5);

    m_elements.append(contentWidget);
}

QList<QWidget*> ImageInfoSubGroupFrame::getElements()
{
    return m_elements;
}