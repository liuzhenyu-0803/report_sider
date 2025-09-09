#ifndef TAGNOTESUBGROUP_H
#define TAGNOTESUBGROUP_H

#include "FieldSubGroup.h"
#include "views/business_components/draggable/field_draggable/FieldDraggable.h"
#include "models/model.h"
#include <QPair>
#include <QStringList>

class TagNoteSubGroup : public FieldSubGroup
{
    Q_OBJECT

public:
    explicit TagNoteSubGroup(QWidget *parent = nullptr);
    virtual ~TagNoteSubGroup();

    // 实现基类虚接口函数
    virtual QList<QWidget*> getElements() override;

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void updateFieldDraggables();
    
private slots:
    void onTemplateSelectionChanged();
    
private:
    
    QList<QWidget*> m_elements;
    QList<QPair<QString, QStringList>> m_templateData;
    QList<FieldDraggable*> m_fieldDraggables; // 固定10个FieldDraggable
    class TemplateTitleSelector* m_templateSelector = nullptr;
    QWidget* m_contentWidget = nullptr;
    class QVBoxLayout* m_contentLayout = nullptr;
};

#endif // TAGNOTESUBGROUP_H
