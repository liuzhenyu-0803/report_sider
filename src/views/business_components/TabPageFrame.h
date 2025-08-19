#ifndef TABPAGEFRAME_H
#define TABPAGEFRAME_H

#include <QFrame>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QString>

// 前置声明
class ConfigModel;
class GroupModel;
class ElementModel;
class UnitElementModel;
class GroupFrame;

class TabPageFrame : public QFrame
{
    Q_OBJECT

public:
    explicit TabPageFrame(QWidget *parent = nullptr);
    virtual ~TabPageFrame();

    // 加载配置数据
    void loadConfig(const QString& configPath);

private:
    void setupUI();
    void createGroupViews();
    
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_contentLayout;
    QScrollArea *m_scrollArea;
    
    ConfigModel *m_configModel;
};

#endif // TABPAGEFRAME_H