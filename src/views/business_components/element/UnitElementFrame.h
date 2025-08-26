#pragma once

#include "ElementFrame.h"

#include "QcLabel.h"
#include "QcMultiLineText.h"
#include "QcIconButton.h"
#include "views/business_components/more_menu/MoreMenu.h"

#include <QVBoxLayout>

class UnitElementFrame : public ElementFrame
{
    Q_OBJECT

public:
    explicit UnitElementFrame(QWidget *parent = nullptr);
    virtual ~UnitElementFrame();

protected:
    void paintEvent(QPaintEvent *event) override;

    void loadData() override;

    // 子类实现：返回图标和标题
    virtual QString getIcon() const = 0;
    virtual QString getText() const = 0;
    // 实现父类虚接口：返回拖拽时的 MimeData
    virtual QMimeData* getMimeData() const override = 0;

    void onIconButtonClicked();

    void setIconButtonVisible(bool visible);

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