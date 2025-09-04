#ifndef RULETYPETITLESELECTOR_H
#define RULETYPETITLESELECTOR_H

#include "views/common_components/TitleSelector.h"

class RuleTypeTitleSelector : public TitleSelector
{
    Q_OBJECT

public:
    enum RuleType
    {
        G, // 全局
        P, // 点
        L, // 线
        Fl, // 折线
        R, // 矩形
        Ep, // 椭圆
        Po // 多边形
    };

    explicit RuleTypeTitleSelector(QWidget *parent = nullptr);
    ~RuleTypeTitleSelector();

    int getCurrentType() const;
    QString getCurrentTypeText() const;
    QString getTypeString(int type) const;
};

#endif // RULETYPETITLESELECTOR_H