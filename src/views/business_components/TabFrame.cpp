#include "TabFrame.h"
#include "TabPageFrame.h"
#include "global/global.h"

TabFrame::TabFrame(QWidget *parent)
    : QWidget(parent)
{
    // 创建按钮组容器
    buttonContainer = new QFrame(this);
    buttonContainer->setObjectName("buttonContainer");
    buttonContainer->setFixedHeight(32);
    buttonContainer->setStyleSheet(QString("#buttonContainer { margin-left: %1px; margin-right: %2px; }").arg(MARGIN_HORIZONTAL_TAB).arg(MARGIN_HORIZONTAL_TAB));

    // 创建按钮
    unitButton = new QPushButton("unitButton", this);
    unitButton->setObjectName("unitButton");
    unitButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    unitButton->setCheckable(true);
    fieldButton = new QPushButton("fieldButton", this);
    fieldButton->setObjectName("fieldButton");
    fieldButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fieldButton->setCheckable(true);

    // 创建按钮组并添加按钮
    tabButtonGroup = new QButtonGroup(this);
    tabButtonGroup->addButton(unitButton, 0);
    tabButtonGroup->addButton(fieldButton, 1);
    
    // 连接按钮组信号到槽函数
    connect(tabButtonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &TabFrame::switchTab);
    
    // 创建按钮布局
    buttonLayout = new QHBoxLayout(buttonContainer);
    buttonLayout->setContentsMargins(0, 0, 0, 0);
    buttonLayout->setSpacing(0);
    buttonLayout->addWidget(unitButton);
    buttonLayout->addWidget(fieldButton);
    buttonContainer->setLayout(buttonLayout);
    
    // 创建提示信息浏览器
    infoTip = new InnerTip(this);
    infoTip->setText("Drag/click to copy the content you want to the corresponding position in the report");
    infoTip->setContentsMargins(MARGIN_HORIZONTAL_TIP, 0, MARGIN_HORIZONTAL_TIP, 0);

    // 创建堆栈窗口
    stackedWidget = new QStackedWidget(this);
    // 创建TabPageFrame实例并添加到stackedWidget
    TabPageFrame *unitPage = new TabPageFrame(this);
    unitPage->loadConfig(":/config/unit_config.json");
    TabPageFrame *fieldPage = new TabPageFrame(this);
    fieldPage->loadConfig(":/config/field_config.json");
    stackedWidget->addWidget(unitPage);
    stackedWidget->addWidget(fieldPage);
    
    // 创建主布局
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(buttonContainer);
    mainLayout->addSpacing(8);
    mainLayout->addWidget(infoTip);
    mainLayout->addWidget(stackedWidget);
    setLayout(mainLayout);
    
    // 默认选中第一个按钮
    unitButton->setChecked(true);
}

TabFrame::~TabFrame()
{
}

void TabFrame::addPage(QWidget *page, const QString &title)
{
    stackedWidget->addWidget(page);
}

void TabFrame::switchTab(int index)
{
    if (index >= 0 && index < stackedWidget->count()) {
        stackedWidget->setCurrentIndex(index);
    }
}