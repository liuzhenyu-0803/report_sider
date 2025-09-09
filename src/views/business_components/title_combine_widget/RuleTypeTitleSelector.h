#ifndef RULETYPETITLESELECTOR_H
#define RULETYPETITLESELECTOR_H

#include "views/common_components/TitleSelector.h"
#include <QList>

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

    explicit RuleTypeTitleSelector(QWidget *parent, QList<int> filterTypes = QList<int>());
    ~RuleTypeTitleSelector();

    int getCurrentType() const;
    QString getCurrentTypeName() const;
    QString getCurrentTypeDescription() const;
    QString getCurrentTypeProtocal() const;
    QString getTypeName(int type) const;
    QString getTypeProtocal(int type) const;
    QString getTypeDescription(int type) const;
};

#endif // RULETYPETITLESELECTOR_H