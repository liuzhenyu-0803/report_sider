#include "TagNoteDraggable.h"
#include <QMimeData>
#include <QIcon>

TagNoteDraggable::TagNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIconButtonVisible(true);

    auto contentLayout = getMoreMenuContentLayout();

    contentLayout->setSpacing(5);

    m_radio1Button = new MicroUI::QcRadioButton();
    m_radio1Button->setText("muban_111111111111111");
    contentLayout->addWidget(m_radio1Button);

    m_radio2Button = new MicroUI::QcRadioButton();
    m_radio2Button->setText("muban_222222222222222");
    contentLayout->addWidget(m_radio2Button);
}

TagNoteDraggable::~TagNoteDraggable()
{
}

QString TagNoteDraggable::getIcon() const
{
    return ":/images/tag_note.svg";
}

QString TagNoteDraggable::getText() const
{
    return "Tag Note";
}

QMimeData* TagNoteDraggable::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TagNoteDraggable");
    mimeData->setData("application/x-tagnote", QByteArray());
    
    return mimeData;
}
