#pragma once

#include "views/business_components/draggable/Draggable.h"
#include "QcIconButton.h"
#include "views/business_components/more_menu/MoreMenu.h"

class FieldDraggable : public Draggable
{
    Q_OBJECT

public:
    explicit FieldDraggable(QWidget *parent = nullptr);
    virtual ~FieldDraggable();

    // 设置文本内容
    void setText(const QString& text);

    void setIconButtonVisible(bool visible);
    QWidget *getMoreMenu() const;
    void setMoreMenuTitle(const QString &title);
    QLayout *getMoreMenuContentLayout() const;

protected:    
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onIconButtonClicked();

private:
    MicroUI::QcIconButton *m_iconButton = nullptr;  
    MoreMenu *m_moreMenu = nullptr;
};