#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class HeaderBar : public QWidget {
    Q_OBJECT

public:
    explicit HeaderBar(QWidget *parent = nullptr);
    ~HeaderBar();

    // 提供访问子控件的方法
    QLabel* titleLabel() const { return m_titleLabel; }
    QPushButton* pinButton() const { return m_pinBtn; }
    QPushButton* minimizeButton() const { return m_minimizeBtn; }
    QPushButton* closeButton() const { return m_closeBtn; }

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLabel *m_titleLabel;
    QPushButton *m_pinBtn;
    QPushButton *m_minimizeBtn;
    QPushButton *m_closeBtn;
};