#pragma once

#include "UnitDraggable.h"
#include "views/business_components/more_menu/MoreMenu.h"
#include "models/model.h"
#include "QcRadioButton.h"
#include <QIcon>
#include <QMimeData>
#include <QString>
#include <QList>
#include <QPair>
#include <QStringList>

class TagNoteDraggable : public UnitDraggable
{
    Q_OBJECT

public:
    explicit TagNoteDraggable(QWidget *parent = nullptr);
    virtual ~TagNoteDraggable();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    // 生成表格行的辅助方法
    QString generateTableRows(const QStringList &keys);

private:
    QList<MicroUI::QcRadioButton*> m_radioButtons;
    QList<QPair<QString, QStringList>> m_templateData;
};
