#pragma once

#include <QWidget>
#include <QVariant>

// 前置声明ViewModel类
class ImageElementViewModel;

class Element : public QWidget {
    Q_OBJECT

public:
    explicit Element(ImageElementViewModel *viewModel, QWidget *parent = nullptr);
    ~Element() override;
    
    void setHtml(const QString &html);
    void setImageData(const QVariant &image);
    void setText(const QString &text);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    ImageElementViewModel *m_viewModel;
    QString m_html;
    QVariant m_imageData;
    QString m_text;
};