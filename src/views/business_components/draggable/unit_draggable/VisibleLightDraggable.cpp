#include "VisibleLightDraggable.h"
#include <QMimeData>
#include <QIcon>

VisibleLightDraggable::VisibleLightDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIconButtonVisible(true);

    auto contentLayout = getMoreMenuContentLayout();

    contentLayout->setSpacing(5);

    m_radio1Button = new MicroUI::QcRadioButton();
    m_radio1Button->setText("duiqi_kejianguang");
    contentLayout->addWidget(m_radio1Button);

    m_radio2Button = new MicroUI::QcRadioButton();
    m_radio2Button->setText("quanjing_kejianguang");
    contentLayout->addWidget(m_radio2Button);
}

VisibleLightDraggable::~VisibleLightDraggable()
{

}

QString VisibleLightDraggable::getIcon() const
{
    return ":/images/visible_light.svg";
}

QString VisibleLightDraggable::getText() const
{
    return "Visible Light";
}

QMimeData* VisibleLightDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("VisibleLightDraggable");
    mimeData->setData("application/x-visiblelight", QByteArray());
    
    return mimeData;
}
