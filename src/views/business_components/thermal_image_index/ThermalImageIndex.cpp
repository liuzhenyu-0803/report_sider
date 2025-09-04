#include "ThermalImageIndex.h"

#include "global/global.h"
#include "views/common_components/InnerTip.h"
#include "models/model.h"

ThermalImageIndex::ThermalImageIndex(QWidget *parent)
    : QWidget(parent)
{
    // 创建顶部布局，包含label和spinbox
    label = new MicroUI::QcLabel(this);
    label->setTextColorParams("#4B4B4B");
    QFont font = label->font();
    font.setPixelSize(12);
    font.setBold(true);
    label->setFont(font);
    label->setText("thermal image index");

    // 设置SpinBox的范围为1以上的整数
    spinBox = new SpinBox(this);
    spinBox->setFixedSize(160, 28);
    spinBox->setMinimum(1);
    spinBox->setMaximum(999999); // 设置一个合理的最大值
    
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->setContentsMargins(MARGIN_HORIZONTAL_NORMAL, 0, MARGIN_HORIZONTAL_NORMAL, 0);
    topLayout->addWidget(label);
    topLayout->addWidget(spinBox);
    
    // 创建底部提示label，使用InnerTip替换原有的QLabel
    InnerTip *tipLabel = new InnerTip(this);
    tipLabel->setContentsMargins(MARGIN_HORIZONTAL_TIP, 0, MARGIN_HORIZONTAL_TIP, 0);
    tipLabel->setText("Tips: The following data is linked to heatmap sequence numbers.");
    tipLabel->setStyleType(InnerTip::Gray);  // 使用灰色样式，匹配原有样式
    tipLabel->setShowIcon(false);  // 不显示图标

    // 创建主垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(8);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(tipLabel);
    setLayout(mainLayout);

    Model::getInstance()->setThermalImageIndex(spinBox->value());

    connect(spinBox, QOverload<int>::of(&SpinBox::valueChanged), this, [=](int value) {
        Model::getInstance()->setThermalImageIndex(value);
    });
}

ThermalImageIndex::~ThermalImageIndex()
{

}

int ThermalImageIndex::getIndex() const
{
    return spinBox->value();
}