#ifndef ABSLOWERCENTERWIDGET_H
#define ABSLOWERCENTERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <lowerbottomwidget.h>
#include <lowertopwidget.h>

class AbsLowerCenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AbsLowerCenterWidget(QWidget *parent = 0);
    LowerTopWidget *getTopWidget(void){return TopWidget;}
signals:

public slots:
    void view(){setVisible(true);}
protected:
    QVBoxLayout *layout;
    LowerBottomWidget* BottomWidget;
    LowerTopWidget *TopWidget;
    virtual void InitUi(void) = 0;
};

#endif // ABSLOWERCENTERWIDGET_H
