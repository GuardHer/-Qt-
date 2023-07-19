#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>
#include <QResource>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPoint diff_;
    int idx; // 图像索引变量

private:
    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
};
#endif // WIDGET_H
