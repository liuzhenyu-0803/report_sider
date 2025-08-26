#include "FieldInfoGroupFrame.h"
#include "views/business_components/element/FieldElementFrame.h"
#include <QVBoxLayout>

FieldInfoGroupFrame::FieldInfoGroupFrame(QWidget *parent)
    : FieldGroupFrame(parent)
{
    // 初始化FieldInfoGroupFrame
    // 添加一些示例元素
    for (int i = 0; i < 3; ++i) {
        FieldElementFrame *element = new FieldElementFrame(this);
        m_fieldElements.append(element);
    }
    
    // 设置组标题
    setGroupTitle("Field Info Group");
}

FieldInfoGroupFrame::~FieldInfoGroupFrame()
{
    // 清理资源
    qDeleteAll(m_fieldElements);
}

QList<ElementFrame*> FieldInfoGroupFrame::getElements()
{
    // 将字段元素转换为基类指针列表并返回
    QList<ElementFrame*> elements;
    for (FieldElementFrame *element : m_fieldElements) {
        elements.append(element);
    }
    return elements;
}