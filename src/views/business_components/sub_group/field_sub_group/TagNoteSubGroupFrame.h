#ifndef TAGNOTESUBGROUPFRAME_H
#define TAGNOTESUBGROUPFRAME_H

#include "../FieldSubGroupFrame.h"

class TagNoteSubGroupFrame : public FieldSubGroupFrame
{
    Q_OBJECT

public:
    explicit TagNoteSubGroupFrame(QWidget *parent = nullptr);
    virtual ~TagNoteSubGroupFrame();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

private:
    void createElements();
    
    QList<QWidget*> m_elements;
};

#endif // TAGNOTESUBGROUPFRAME_H