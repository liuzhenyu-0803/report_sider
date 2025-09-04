#ifndef FIELDTABPAGE_H
#define FIELDTABPAGE_H

#include "TabPage.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

// 前置声明
class TemperatureUnitFieldGroup;
class NoteFieldGroup;
class ImagePropertyFieldGroup;
class Group;

class FieldTabPage : public TabPage
{
    Q_OBJECT

public:
    explicit FieldTabPage(QWidget *parent = nullptr);
    virtual ~FieldTabPage();

private slots:
    void onGroupExpanded(Group* expandedGroup);

private:
    void loadContent();
    
    // 三个group的成员变量
    TemperatureUnitFieldGroup* m_temperatureUnitGroup = nullptr;
    NoteFieldGroup* m_noteGroup = nullptr;
    ImagePropertyFieldGroup* m_imagePropertyGroup = nullptr;
};

#endif // FIELDTABPAGE_H