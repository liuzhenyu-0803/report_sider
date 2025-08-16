#include "TabFrame.h"

TabFrame::TabFrame(QWidget *parent)
    : QWidget(parent)
{
    // 创建按钮组容器
    buttonContainer = new QFrame(this);
    
    // 创建按钮
    unitButton = new QPushButton("unit", this);
    fieldButton = new QPushButton("field", this);
    
    // 连接按钮信号到槽函数
    connect(unitButton, &QPushButton::clicked, this, &TabFrame::switchToUnit);
    connect(fieldButton, &QPushButton::clicked, this, &TabFrame::switchToField);
    
    // 创建按钮布局
    buttonLayout = new QHBoxLayout(buttonContainer);
    buttonLayout->addWidget(unitButton);
    buttonLayout->addWidget(fieldButton);
    buttonLayout->addStretch(); // 添加弹性空间
    buttonContainer->setLayout(buttonLayout);
    
    // 创建提示信息浏览器
    infoBrowser = new QTextBrowser(this);
    infoBrowser->setText("Drag/click to copy the content you want to the corresponding position in the report");
    
    // 创建堆栈窗口
    stackedWidget = new QStackedWidget(this);
    
    // 创建主布局
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(buttonContainer);
    mainLayout->addWidget(infoBrowser);
    mainLayout->addWidget(stackedWidget);
    mainLayout->addStretch(); // 添加弹性空间
    setLayout(mainLayout);
}

TabFrame::~TabFrame()
{
}

void TabFrame::addPage(QWidget *page, const QString &title)
{
    stackedWidget->addWidget(page);
}

void TabFrame::switchToUnit()
{
    if (stackedWidget->count() > 0) {
        stackedWidget->setCurrentIndex(0);
    }
}

void TabFrame::switchToField()
{
    if (stackedWidget->count() > 1) {
        stackedWidget->setCurrentIndex(1);
    }
}