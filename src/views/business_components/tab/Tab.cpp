#include "Tab.h"
#include "views/business_components/tab/TabPage.h"
#include "views/business_components/tab/UnitTabPage.h"
#include "views/business_components/tab/FieldTabPage.h"
#include "global/global.h"

Tab::Tab(QWidget *parent)
    : QWidget(parent)
{
    // 创建按钮组容器
    buttonContainer = new QFrame(this);
    buttonContainer->setObjectName("buttonContainer");
    buttonContainer->setFixedHeight(32);
    buttonContainer->setStyleSheet(QString("#buttonContainer { margin-left: %1px; margin-right: %2px; }").arg(MARGIN_HORIZONTAL_TAB).arg(MARGIN_HORIZONTAL_TAB));

    // 创建按钮
    unitButton = new QPushButton("Unit", this);
    unitButton->setObjectName("unitButton");
    unitButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    unitButton->setCheckable(true);
    fieldButton = new QPushButton("Field", this);
    fieldButton->setObjectName("fieldButton");
    fieldButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fieldButton->setCheckable(true);

    // 创建按钮组并添加按钮
    tabButtonGroup = new QButtonGroup(this);
    tabButtonGroup->addButton(unitButton, 0);
    tabButtonGroup->addButton(fieldButton, 1);
    
    // 连接按钮组信号到槽函数
    connect(tabButtonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &Tab::switchTab);
    
    // 创建按钮布局
    buttonLayout = new QHBoxLayout(buttonContainer);
    buttonLayout->setContentsMargins(0, 0, 0, 0);
    buttonLayout->setSpacing(0);
    buttonLayout->addWidget(unitButton);
    buttonLayout->addWidget(fieldButton);
    buttonContainer->setLayout(buttonLayout);
    
    // 创建提示信息浏览器
    infoTip = new InnerTip(this);
    infoTip->setText("Drag/Click to copy the desired content to the corresponding location in the report.");
    infoTip->setStyleSheet(infoTip->styleSheet() + QString("InnerTip { margin-left: %1px; margin-right: %2px; }").arg(MARGIN_HORIZONTAL_TAB).arg(MARGIN_HORIZONTAL_TAB));

    // 创建堆栈窗口
    stackedWidget = new QStackedWidget(this);
    // 创建TabPage实例并添加到stackedWidget
    TabPage *unitPage = new UnitTabPage(this);
    TabPage *fieldPage = new FieldTabPage(this);
    stackedWidget->addWidget(unitPage);
    stackedWidget->addWidget(fieldPage);
    
    // 创建主布局
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(buttonContainer);
    mainLayout->addSpacing(8);
    mainLayout->addWidget(infoTip);
    mainLayout->addSpacing(16);
    mainLayout->addWidget(stackedWidget);
    setLayout(mainLayout);
    
    // 默认选中第一个按钮
    unitButton->setChecked(true);
}

Tab::~Tab()
{
}

void Tab::addPage(QWidget *page, const QString &title)
{
    stackedWidget->addWidget(page);
}

void Tab::switchTab(int index)
{
    if (index >= 0 && index < stackedWidget->count()) {
        stackedWidget->setCurrentIndex(index);
    }
}