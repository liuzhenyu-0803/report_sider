#include "ThermalImageIndex.h"

ThermalImageIndex::ThermalImageIndex(QWidget *parent)
    : QWidget(parent)
{
    // 创建顶部布局，包含label和spinbox
    label = new QLabel("thermal_image_index", this);
    spinBox = new SpinBox(this);
    
    // 设置SpinBox的范围为1以上的整数
    spinBox->setMinimum(1);
    spinBox->setMaximum(999999); // 设置一个合理的最大值
    
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(label);
    topLayout->addWidget(spinBox);
    topLayout->addStretch(); // 添加弹性空间
    
    // 创建底部提示label
    QLabel *tipLabel = new QLabel("tips：bind thermal image index", this);
    
    // 创建主垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(tipLabel);
    mainLayout->addStretch(); // 添加弹性空间
    setLayout(mainLayout);
}

ThermalImageIndex::~ThermalImageIndex()
{
}

int ThermalImageIndex::getIndex() const
{
    return spinBox->value();
}