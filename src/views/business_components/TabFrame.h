#ifndef TABFRAME_H
#define TABFRAME_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QTextBrowser>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include "../common_components/SpinBox.h"
#include "../common_components/InnerTip.h"

// 前置声明新组件
class TabPage;

class TabFrame : public QWidget
{
    Q_OBJECT

public:
    explicit TabFrame(QWidget *parent = nullptr);
    virtual ~TabFrame();

    // 提供添加页面到StackedWidget的接口
    void addPage(QWidget *page, const QString &title);

private slots:
    void switchTab(int index);

private:
    QFrame *buttonContainer = nullptr;
    QPushButton *unitButton = nullptr;
    QPushButton *fieldButton = nullptr;
    QButtonGroup *tabButtonGroup = nullptr;
    InnerTip *infoTip = nullptr;
    QStackedWidget *stackedWidget = nullptr;

    QVBoxLayout *mainLayout = nullptr;
    QHBoxLayout *buttonLayout = nullptr;
};
#endif // TABFRAME_H