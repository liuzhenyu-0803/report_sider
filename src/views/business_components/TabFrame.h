#ifndef TABFRAME_H
#define TABFRAME_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QTextBrowser>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../common_components/SpinBox.h"

// 前置声明新组件
class UnitFrame;
class FieldFrame;

class TabFrame : public QWidget
{
    Q_OBJECT

public:
    explicit TabFrame(QWidget *parent = nullptr);
    virtual ~TabFrame();

    // 提供添加页面到StackedWidget的接口
    void addPage(QWidget *page, const QString &title);

private slots:
    void switchToUnit();
    void switchToField();

private:
    QFrame *buttonContainer;
    QPushButton *unitButton;
    QPushButton *fieldButton;
    QTextBrowser *infoBrowser;
    QStackedWidget *stackedWidget;
    
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonLayout;
};

#endif // TABFRAME_H