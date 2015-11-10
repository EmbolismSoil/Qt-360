#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QWidget>
#include <closebutton.h>
#include <QHBoxLayout>

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
    Button *optimizeBtn;
    Button *safeCheckBtn;
    Button *cleanBtn;
    QHBoxLayout *layout;
};

#endif // BOTTOMWIDGET_H
