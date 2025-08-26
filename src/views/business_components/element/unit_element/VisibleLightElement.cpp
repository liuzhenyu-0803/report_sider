#include "VisibleLightElement.h"
#include <QMimeData>
#include <QIcon>

VisibleLightElement::VisibleLightElement(QWidget *parent)
    : UnitElementFrame(parent)
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

VisibleLightElement::~VisibleLightElement()
{

}

QString VisibleLightElement::getIcon() const
{
    return ":/images/visible_light.svg";
}

QString VisibleLightElement::getText() const
{
    return "Visible Light";
}

QMimeData* VisibleLightElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("VisibleLightElement");
    mimeData->setData("application/x-visiblelight", QByteArray());
    
    return mimeData;
}