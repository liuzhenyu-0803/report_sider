#pragma once

#include <QWidget>
#include <QVariant>

class Element : public QWidget {
    Q_OBJECT

public:
    explicit Element(QWidget *parent = nullptr);
    ~Element() override;
    
    void setHtml(const QString &html);
    void setImageData(const QVariant &image);
    void setText(const QString &text);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString m_html;
    QVariant m_imageData;
    QString m_text;
};