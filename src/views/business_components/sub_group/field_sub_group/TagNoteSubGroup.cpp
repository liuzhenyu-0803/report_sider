#include "TagNoteSubGroup.h"
#include "views/business_components/title_combine_widget/TemplateTitleSelector.h"
#include <QJsonObject>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QMimeData>

TagNoteSubGroup::TagNoteSubGroup(QWidget *parent)
    : FieldSubGroup(parent)
{
    setGroupTitle(tr("LabelNotesName"));
    
    // 获取模板数据
    Model *model = Model::getInstance();
    m_templateData = model->getTextRemarkTemplateKeys();
}

TagNoteSubGroup::~TagNoteSubGroup()
{
}

QList<QWidget*> TagNoteSubGroup::getElements()
{
    if (m_elements.isEmpty()) {
        m_contentWidget = new QWidget(this);
        m_contentLayout = new QVBoxLayout(m_contentWidget);
        m_contentLayout->setContentsMargins(0, 0, 0, 0);
        m_contentLayout->setSpacing(10);

        m_templateSelector = new TemplateTitleSelector(this);
        m_contentLayout->addWidget(m_templateSelector);
        
        // 连接信号槽，监听模板选择变化
        connect(m_templateSelector, &TitleSelector::currentIndexChanged,
                this, &TagNoteSubGroup::onTemplateSelectionChanged);

        // 固定创建10个FieldDraggable
        for (int i = 0; i < 10; ++i) {
            FieldDraggable *fieldDraggable = new FieldDraggable(this);
            fieldDraggable->setText(""); // 初始为空
            fieldDraggable->setVisible(false); // 初始隐藏
            fieldDraggable->installEventFilter(this);
            
            m_fieldDraggables.append(fieldDraggable);
            m_contentLayout->addWidget(fieldDraggable);
        }

        m_elements.append(m_contentWidget);
    }
    return m_elements;
}

bool TagNoteSubGroup::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            // 检查是否是动态创建的FieldDraggable
            FieldDraggable *clickedDraggable = qobject_cast<FieldDraggable*>(watched);
            if (clickedDraggable && m_fieldDraggables.contains(clickedDraggable)) {
                // 为点击的FieldDraggable设置MimeData
                QString keyText = clickedDraggable->getCustomData()["text"].toString();
                
                auto mimeData = new QMimeData();
                // 使用{{rm{number}.tgt.{key}}}格式，其中number从Model::getInstance()->getThermalImageIndex()获取
                QString mimeText = QString("{{rm%1.tgt.%2}}").arg(Model::getInstance()->getThermalImageIndex()).arg(keyText);
                mimeData->setText(mimeText);
                clickedDraggable->setMimeData(mimeData);
            }
        }
    }
    return FieldSubGroup::eventFilter(watched, event);
}

void TagNoteSubGroup::onTemplateSelectionChanged()
{
    updateFieldDraggables();
}

void TagNoteSubGroup::updateFieldDraggables()
{
    // 获取当前选中的模板索引
    int currentIndex = m_templateSelector->currentIndex();
    
    // 首先隐藏所有FieldDraggable
    for (FieldDraggable *draggable : m_fieldDraggables) {
        draggable->setVisible(false);
    }
    
    // 跳过"None"选项（索引0）
    if (currentIndex <= 0 || currentIndex > m_templateData.size()) {
        return;
    }
    
    // 获取对应模板的Keys（索引需要减1，因为第0个是"None"）
    int templateIndex = currentIndex - 1;
    const QStringList &keys = m_templateData[templateIndex].second;
    
    // 根据keys设置对应的FieldDraggable的文本和可见性
    int keyCount = qMin(keys.size(), m_fieldDraggables.size());
    for (int i = 0; i < keyCount; ++i) {
        FieldDraggable *draggable = m_fieldDraggables[i];
        draggable->setText(keys[i]);
        draggable->setCustomData(QJsonObject{{"text", keys[i]}});
        draggable->setVisible(true);
    }
}