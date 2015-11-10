#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QWidget>
#include <closebutton.h>
#include <QHBoxLayout>
#include <buttonwithname.h>

class bottomBaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit bottomBaseWidget(QWidget *parent = 0);

protected:
    //virtual void paintEvent ( QPaintEvent * event);
    virtual QSize	sizeHint () const;
signals:

public slots:
private:
    ButtonWithName *optimizeBtn;
    ButtonWithName *safeCheckBtn;
    ButtonWithName *cleanBtn;

    ButtonWithName *softMngBtn;
    ButtonWithName *humanSvrBtn;
    ButtonWithName *mobileBtn;
    ButtonWithName *speedBtn;
    ButtonWithName *moreBtn;
    Button *routerBtn;

    QHBoxLayout *layout;
};

#endif // BOTTOMWIDGET_H
