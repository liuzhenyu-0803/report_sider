#include "TagNoteDraggable.h"
#include <QMimeData>
#include <QIcon>

TagNoteDraggable::TagNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/tag_note.svg");
    setText("Tag Note");
    
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

void TagNoteDraggable::mousePressEvent(QMouseEvent *event)
{
    // QMimeData *mimeData = new QMimeData();
    // mimeData->setHtml(MicroUI::GetFileContent("://html/tag_note.html").arg(Model::getInstance()->getThermalImageIndex()));
    // setMimeData(mimeData);
}
