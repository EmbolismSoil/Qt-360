#ifndef LOWERTOPWIDGET_H
#define LOWERTOPWIDGET_H

#include <QWidget>
#include <titlebar.h>
#include <QString>
#include <QLabel>
#include <closebutton.h>

class LowerTopWidget : public QWidget
{
    Q_OBJECT
public:
 //   explicit LowerTopWidget(QWidget *parent = 0);
    LowerTopWidget(QString BtnLeft,QString BtnRight,int xnum, int ynum,
                   QString TopLabel = NULL, QString bottomLabel = NULL, QWidget *parent = 0);
    Button *TitleBtn(void){return titleBtn;}
signals:

protected:
    //virtual  QSize sizeHint () const;
public slots:

private:
    titleBar *title;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout;
    Button *leftBtn;
    Button *rightBtn;
    Button *titleBtn;
};

#endif // LOWERTOPWIDGET_H
