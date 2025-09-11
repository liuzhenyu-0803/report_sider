#include "ImageInfoSubGroup.h"
#include "views/business_components/draggable/unit_draggable/ImageInfoDraggable.h"
#include "views/business_components/title_combine_widget/ParameterTitleSelector.h"
#include "models/model.h"
#include <QJsonObject>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QMimeData>

ImageInfoSubGroup::ImageInfoSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle(tr("ImageInformationName"));
}

ImageInfoSubGroup::~ImageInfoSubGroup()
{
    
}

QList<QWidget*> ImageInfoSubGroup::getElements()
{
    if (m_elements.isEmpty()) {
        auto contentWidget = new QWidget(this);
        auto contentWidgetLayout = new QVBoxLayout(contentWidget);
        contentWidgetLayout->setContentsMargins(0, 0, 0, 0);
        contentWidgetLayout->setSpacing(10);

        dragElement1 = new FieldDraggable(this);
        setDragElement1Text();
        dragElement1->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement1);

        dragElement1->setIconButtonVisible(true);
        dragElement1->setMoreMenuTitle(tr("ImageNameName"));
        radioButton1 = new MicroUI::QcRadioButton(this);
        radioButton1->setText("DisplayFileExtensiName");
        auto layout = dragElement1->getMoreMenuContentLayout();
        layout->addWidget(radioButton1);

        dragElement2 = new FieldDraggable(this);
        setDragElement2Text();
        dragElement2->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement2);

        dragElement3 = new FieldDraggable(this);
        setDragElement3Text();
        dragElement3->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement3);

        dragElement4 = new FieldDraggable(this);
        setDragElement4Text();
        dragElement4->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement4);

        dragElement5 = new FieldDraggable(this);
        setDragElement5Text();
        dragElement5->installEventFilter(this);
        contentWidgetLayout->addWidget(dragElement5);

        m_elements.append(contentWidget);
    }
    return m_elements;
}

bool ImageInfoSubGroup::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            if (watched == dragElement1) {
                setDragElement1MimeData();
            } else if (watched == dragElement2) {
                setDragElement2MimeData();
            } else if (watched == dragElement3) {
                setDragElement3MimeData();
            } else if (watched == dragElement4) {
                setDragElement4MimeData();
            } else if (watched == dragElement5) {
                setDragElement5MimeData();
            }
        }
    }
    return FieldSubGroup::eventFilter(watched, event);
}

void ImageInfoSubGroup::setDragElement1Text()
{
    dragElement1->setText(tr("ImageNameButton"));
}

void ImageInfoSubGroup::setDragElement2Text()
{
    dragElement2->setText(tr("DetectorResolutionButton"));
}

void ImageInfoSubGroup::setDragElement3Text()
{
    dragElement3->setText(tr("ImageSizeButton"));
}

void ImageInfoSubGroup::setDragElement4Text()
{
    dragElement4->setText(tr("ShootingTimeButton"));
}

void ImageInfoSubGroup::setDragElement5Text()
{
    dragElement5->setText(tr("SavePathButton"));
}

void ImageInfoSubGroup::setDragElement1MimeData()
{
    auto mimeData = new QMimeData();
    if (radioButton1->isChecked())
    {
        mimeData->setText(QString("{{rm%1.imgn.ext}}").arg(Model::getInstance()->getThermalImageIndex()));
    }
    else
    {
        mimeData->setText(QString("{{rm%1.imgn}}").arg(Model::getInstance()->getThermalImageIndex()));
    }
    dragElement1->setMimeData(mimeData);
}

void ImageInfoSubGroup::setDragElement2MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.IRr}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement2->setMimeData(mimeData);
}

void ImageInfoSubGroup::setDragElement3MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.psz}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement3->setMimeData(mimeData);
}

void ImageInfoSubGroup::setDragElement4MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.cap}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement4->setMimeData(mimeData);
}

void ImageInfoSubGroup::setDragElement5MimeData()
{
    auto mimeData = new QMimeData();
    mimeData->setText(QString("{{rm%1.fpt}}").arg(Model::getInstance()->getThermalImageIndex()));
    dragElement5->setMimeData(mimeData);
}