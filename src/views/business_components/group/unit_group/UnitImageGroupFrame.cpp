#include "UnitImageGroupFrame.h"
#include "views/common_components/FlowLayout.h"
#include <QVBoxLayout>

UnitImageGroupFrame::UnitImageGroupFrame(QWidget *parent)
    : UnitGroupFrame(parent)
{
    // 初始化UnitImageGroupFrame
    // 添加一些示例元素
    for (int i = 0; i < 3; ++i) {
        UnitThermalImageElement *element = new UnitThermalImageElement(this);
        m_thermalImageElements.append(element);
    }
    
    // 设置组标题
    setGroupTitle("Thermal Image Group");
}

UnitImageGroupFrame::~UnitImageGroupFrame()
{
    // 清理资源
    qDeleteAll(m_thermalImageElements);
}

QList<ElementFrame*> UnitImageGroupFrame::getElements()
{
    // 将热成像元素转换为基类指针列表并返回
    QList<ElementFrame*> elements;
    for (UnitThermalImageElement *element : m_thermalImageElements) {
        elements.append(element);
    }
    return elements;
}