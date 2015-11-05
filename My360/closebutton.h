#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button( QString FileName, int num  = 1, QWidget *parent = 0);

protected:
    QList<QPixmap> pixmatpList;
    int curIndex;
protected:
    virtual void paintEvent ( QPaintEvent * event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent ( QEvent * event );
    virtual  QSize sizeHint () const;

signals:

public slots:

};

#endif // CLOSEBUTTON_H
