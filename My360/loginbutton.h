#ifndef LOGINBUTTON_H
#define LOGINBUTTON_H
#include <closebutton.h>
#include <QPixmap>

class LoginButton : public Button
{
public:
    LoginButton(QString FileName, int num  = 1, QWidget *parent = 0);
    virtual ~LoginButton();

    void setBackGround(QPixmap* bg){background = bg;}
    QPixmap* getBackGround(){return background;}

protected:
    virtual void paintEvent ( QPaintEvent * event);
   // virtual  QSize sizeHint () const;

private:
    QPixmap *background;
};

#endif // LOGINBUTTON_H
