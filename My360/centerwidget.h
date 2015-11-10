#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include <basewidget.h>
#include <bottomwidget.h>

class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);

signals:
    void closeBtnClicked();

public slots:
    void closeClicked();

private:
    QVBoxLayout *layout;
    TopBaseWidget *topWidget;
     bottomBaseWidget  *bottomWidget;
};

#endif // CENTERWIDGET_H
