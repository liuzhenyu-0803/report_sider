#include "TagNoteDraggable.h"
#include <QMimeData>
#include <QIcon>
#include <QDebug>

TagNoteDraggable::TagNoteDraggable(QWidget *parent)
    : UnitDraggable(parent)
{
    setIcon(":/images/tag_note.svg");
    setText(tr("LabelNotesButton"));
    
    setIconButtonVisible(true);
    setMoreMenuTitle(tr("TemplateSelectionName"));

    auto contentLayout = getMoreMenuContentLayout();
    contentLayout->setSpacing(5);

    // 获取模板数据
    Model *model = Model::getInstance();
    m_templateData = model->getTextRemarkTemplateKeys();
    
    // 检查是否有有效的模板（不为空且有非空Keys）
    bool hasValidTemplate = false;
    for (const auto &templatePair : m_templateData) {
        if (!templatePair.second.isEmpty()) {
            hasValidTemplate = true;
            break;
        }
    }
    
    // 根据是否有有效模板设置图标按钮可见性
    setIconButtonVisible(hasValidTemplate);
    
    // 为每个模板文件创建RadioButton
    for (int i = 0; i < m_templateData.size(); ++i) {
        const auto &templatePair = m_templateData[i];
        QString fileName = templatePair.first;
        
        MicroUI::QcRadioButton *radioButton = new MicroUI::QcRadioButton();
        radioButton->setText(fileName);
        radioButton->setProperty("templateIndex", i); // 存储模板索引
        
        m_radioButtons.append(radioButton);
        contentLayout->addWidget(radioButton);
    }
    
    // 默认选中第一个RadioButton
    if (!m_radioButtons.isEmpty()) {
        m_radioButtons.first()->setChecked(true);
    }
}

TagNoteDraggable::~TagNoteDraggable()
{
}

void TagNoteDraggable::mousePressEvent(QMouseEvent *event)
{
    // 检查是否有有效的模板，如果没有则不设置MimeData
    bool hasValidTemplate = false;
    for (const auto &templatePair : m_templateData) {
        if (!templatePair.second.isEmpty()) {
            hasValidTemplate = true;
            break;
        }
    }
    
    if (!hasValidTemplate) {
        // 调用父类的mousePressEvent但不设置MimeData
        UnitDraggable::mousePressEvent(event);
        return;
    }
    
    // 找到当前选中的RadioButton
    int selectedIndex = -1;
    for (int i = 0; i < m_radioButtons.size(); ++i) {
        if (m_radioButtons[i]->isChecked()) {
            selectedIndex = i;
            break;
        }
    }
    
    if (selectedIndex >= 0 && selectedIndex < m_templateData.size()) {
        const QStringList &keys = m_templateData[selectedIndex].second;
        // 只有当选中模板有有效Keys时才设置MimeData
        if (!keys.isEmpty()) {
            QString tableRows = generateTableRows(keys);
            
            QMimeData *mimeData = new QMimeData();
            mimeData->setHtml(MicroUI::GetFileContent(":/html/tag_note.html").arg(tableRows).arg("LabelNotesName"));
            setMimeData(mimeData);
            
            qDebug() << "Generated HTML table for template:" << m_templateData[selectedIndex].first;
        } else {
            qDebug() << "Selected template has no keys, skipping MimeData setting";
        }
    } else {
        qDebug() << "No template selected or invalid selection";
    }
    
    // 调用父类的mousePressEvent以确保拖拽功能正常工作
    UnitDraggable::mousePressEvent(event);
}

QString TagNoteDraggable::generateTableRows(const QStringList &keys)
{
    if (keys.isEmpty()) {
        return "<tr><td colspan='2'>No keys found</td></tr>";
    }
    
    // 获取热成像索引用作rm后面的数字
    int thermalImageIndex = Model::getInstance()->getThermalImageIndex();
    
    QString rows;
    for (const QString &key : keys) {
        rows += QString("<tr><td>%1</td><td>{{rm%2.tgt.%3}}</td></tr>")
                .arg(key)
                .arg(thermalImageIndex)
                .arg(key);
    }
    
    return rows;
}
