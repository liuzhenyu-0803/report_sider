#ifndef TITLELINEEDIT_H
#define TITLELINEEDIT_H

#include "QcLabel.h"
#include "QcLineEditFrame.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include <QStringList>

class TitleLineEdit : public QWidget
{
    Q_OBJECT

signals:
    void currentIndexChanged();

public:
    explicit TitleLineEdit(QWidget *parent = nullptr);
    ~TitleLineEdit();

    void setTitle(const QString &title);
    void setValidator(QValidator *v);

    void setText(const QString &text);
    QString getText() const;

private:
    MicroUI::QcLabel *m_titleLabel = nullptr;
    MicroUI::QcLineEditFrame *m_lineEdit = nullptr;
};

#endif // TITLELINEEDIT_H