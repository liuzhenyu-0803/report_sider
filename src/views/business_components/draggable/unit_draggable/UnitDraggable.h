#pragma once

#include "views/business_components/draggable/Draggable.h"

#include "QcLabel.h"
#include "QcMultiLineText.h"
#include "QcIconButton.h"
#include "views/business_components/more_menu/MoreMenu.h"

#include <QVBoxLayout>

class UnitDraggable : public Draggable
{
    Q_OBJECT

public:
    explicit UnitDraggable(QWidget *parent = nullptr);
    virtual ~UnitDraggable();

protected:
    void paintEvent(QPaintEvent *event) override;

    // 提供给子类的设置接口
    void setIcon(const QString& iconPath);
    void setText(const QString& text);

    void onIconButtonClicked();

    void setIconButtonVisible(bool visible);
    void setIconButtonEnabled(bool enabled);

    QWidget *getMoreMenu() const;
    void setMoreMenuTitle(const QString &title);
    QLayout *getMoreMenuContentLayout() const;

private:
    void setupUI();

private:
    QVBoxLayout *m_layout = nullptr;
    MicroUI::QcLabel *m_iconLabel = nullptr;
    MicroUI::QcMultiLineText *m_multiLineText = nullptr;
    MicroUI::QcIconButton *m_iconButton = nullptr;
    MoreMenu *m_moreMenu = nullptr;
};