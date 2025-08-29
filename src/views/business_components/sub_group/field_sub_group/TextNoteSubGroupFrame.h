#ifndef TEXTNOTESUBGROUPFRAME_H
#define TEXTNOTESUBGROUPFRAME_H

#include "../FieldSubGroupFrame.h"

class TextNoteSubGroupFrame : public FieldSubGroupFrame
{
    Q_OBJECT

public:
    explicit TextNoteSubGroupFrame(QWidget *parent = nullptr);
    virtual ~TextNoteSubGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TEXTNOTESUBGROUPFRAME_H