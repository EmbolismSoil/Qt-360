#ifndef LOWERSPEEDBUTTON_H
#define LOWERSPEEDBUTTON_H

#include <QCheckBox>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QPushButton>

class lowerSpeedButton : public QPushButton
{
    Q_OBJECT
public:
    lowerSpeedButton(QVector<QPixmap>& , QVector<QPixmap>& , QWidget * = 0);
    static lowerSpeedButton *factory(int index, QWidget *parent = 0);
signals:

public slots:
    void sChanged ();
protected:
    virtual void paintEvent ( QPaintEvent * event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent ( QEvent * event );
    //virtual void mousePressEvent ( QMouseEvent * event ) ;
    //virtual void mouseReleaseEvent ( QMouseEvent * event );
    virtual  QSize sizeHint () const;
private:
    QVector<QPixmap> colorPixmap;
    QVector<QPixmap>  grayPixmap;
    QVector<QPixmap> *curPixmap;
    int curIndex;
};

#endif // LOWERSPEEDBUTTON_H
