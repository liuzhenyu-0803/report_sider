#include "NormalImageDraggable.h"
#include "views/business_components/image_creator/image_creator.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

NormalImageDraggable::NormalImageDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/normal_image.svg");
    setText(tr("NormalMapButton"));
}

NormalImageDraggable::~NormalImageDraggable()
{
}

void NormalImageDraggable::mousePressEvent(QMouseEvent *event)
{
    ImageCreator imageCreator;
    imageCreator.setBackgroundColorParams("#FFFAEA");
    imageCreator.setIconPath(":/images/normal_image.svg");
    imageCreator.setText(tr("1-normal image"));
    imageCreator.setMetaData(QString("img:oim1"));

    auto imagePath = qApp->applicationDirPath() + "/normal_image.png";
    imageCreator.createImage(imagePath);

    QMimeData *mimeData = new QMimeData();
    auto url = QUrl::fromLocalFile(imagePath);
    mimeData->setUrls({url});
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
