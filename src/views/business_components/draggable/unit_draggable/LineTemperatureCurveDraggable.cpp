#include "LineTemperatureCurveDraggable.h"
#include "views/business_components/image_creator/image_creator.h"
#include "views/business_components/title_combine_widget/RuleTypeTitleSelector.h"
#include "views/business_components/title_combine_widget/RuleSequenceTitleSpinBox.h"
#include "models/model.h"
#include <QMimeData>
#include <QIcon>

LineTemperatureCurveDraggable::LineTemperatureCurveDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/line_temperature_curve.svg");
    setText(tr("LineTemperatureCurButton"));

    setIconButtonVisible(true);

    setMoreMenuTitle(tr("VisibleLightTypeName"));

    getMoreMenu()->setFixedWidth(232);

    auto contentLayout = getMoreMenuContentLayout();
    contentLayout->setContentsMargins(8, 0, 8, 8);
    contentLayout->setSpacing(8);

    auto hlayout = new QHBoxLayout();
    hlayout->setContentsMargins(0, 0, 0, 0);
    hlayout->setSpacing(6);

    m_selector = new RuleTypeTitleSelector(this);
    hlayout->addWidget(m_selector);

    m_spinBox = new RuleSequenceTitleSpinBox();
    m_spinBox->setEnabled(false);
    hlayout->addWidget(m_spinBox);

    qobject_cast<QBoxLayout *>(contentLayout)->addLayout(hlayout);

    connect(m_selector, &RuleTypeTitleSelector::currentIndexChanged, this, [=]() {
        m_spinBox->setEnabled(m_selector->getCurrentType() != RuleTypeTitleSelector::G);
    });
}

LineTemperatureCurveDraggable::~LineTemperatureCurveDraggable()
{
}

void LineTemperatureCurveDraggable::mousePressEvent(QMouseEvent *event)
{
    ImageCreator imageCreator;
    imageCreator.setBackgroundColorParams("#D2B3FF");
    imageCreator.setIconPath(":/images/line_temperature_curve.svg");
    imageCreator.setText(QString("%1-%2").arg(Model::getInstance()->getThermalImageIndex()).arg(tr("line temperature")));
    if (m_selector->getCurrentType() == RuleTypeTitleSelector::RuleType::G) 
    {
        imageCreator.setMetaData(QString("ct:rm%1.lcr.%2").arg(Model::getInstance()->getThermalImageIndex()).arg(m_selector->getCurrentTypeProtocal()));
    }
    else 
    {
         imageCreator.setMetaData(QString("ct:rm%1.lcr.%2%3").arg(Model::getInstance()->getThermalImageIndex()).arg(m_selector->getCurrentTypeProtocal()).arg(m_spinBox->value()));
    }

    auto imagePath = qApp->applicationDirPath() + "/temperature_line_temperature_curve.png";
    imageCreator.createImage(imagePath);
     
    QMimeData *mimeData = new QMimeData();
    auto url = QUrl::fromLocalFile(imagePath);
    mimeData->setUrls({url});
    setMimeData(mimeData);

    UnitDraggable::mousePressEvent(event);
}
