#include "TemplateTitleSelector.h"
#include "models/model.h"

TemplateTitleSelector::TemplateTitleSelector(QWidget *parent)
    : TitleSelector(parent)
{
    setTitle("Template");
    
    // 获取JSON模板文件数据
    Model *model = Model::getInstance();
    QList<QPair<QString, QStringList>> templateData = model->getTextRemarkTemplateKeys();
    
    QStringList templateNames;
    if (templateData.isEmpty())
    {
        templateNames << tr("NoTemplateAvailablButton"); // 添加默认的"无"选项
        setEnabled(false);
    }
    
    // 添加模板文件名
    for (const auto &templatePair : templateData) {
        templateNames << templatePair.first;
    }
    
    addItems(templateNames);
}

TemplateTitleSelector::~TemplateTitleSelector()
{

}