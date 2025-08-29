#ifndef TITLESELECTOR_H
#define TITLESELECTOR_H

#include "QcLabel.h"
#include "QcSelector.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include <QStringList>

class TitleSelector : public QWidget
{
    Q_OBJECT

signals:
    void currentIndexChanged();

public:
    explicit TitleSelector(QWidget *parent = nullptr);
    ~TitleSelector();

    void setTitle(const QString &title);

    void addItems(const QStringList &texts);

    int currentIndex() const;
    QString currentText() const;

private:
    MicroUI::QcLabel *m_titleLabel = nullptr;
    MicroUI::QcSelector *m_selector = nullptr;
};

#endif // TITLESELECTOR_H