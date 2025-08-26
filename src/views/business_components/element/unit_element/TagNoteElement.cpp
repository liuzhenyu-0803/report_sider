#include "TagNoteElement.h"
#include <QMimeData>
#include <QIcon>

TagNoteElement::TagNoteElement(QWidget *parent)
    : UnitElementFrame(parent)
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

TagNoteElement::~TagNoteElement()
{
}

QString TagNoteElement::getIcon() const
{
    return ":/images/tag_note.svg";
}

QString TagNoteElement::getText() const
{
    return "Tag Note";
}

QMimeData* TagNoteElement::getMimeData() const
{
    QMimeData *mimeData = new QMimeData();
    
    mimeData->setText("TagNoteElement");
    mimeData->setData("application/x-tagnote", QByteArray());
    
    return mimeData;
}