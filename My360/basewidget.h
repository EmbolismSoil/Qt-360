#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <titlebar.h>
#include <loginbutton.h>
#include <nunberwidget.h>

class TopBaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopBaseWidget(QWidget *parent = 0);

    titleBar *getTitleBar(void){return title;}
    typedef  enum {MoveUp, MoveDonw, MoveLeft, MoveRight}MoveDirection;

signals:

public slots:

protected:
    //virtual void paintEvent ( QPaintEvent * event);

private:
    titleBar *title;
    Button *examineBtn;
    Button *safeBtn;
    Button *payinBtn;
    Button *lineBtn;

    LoginButton *loginBtn;
    NunberWidget *number;

};

#endif // BASEWIDGET_H
