#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>

class Button : public QPushButton
{
    Q_OBJECT
public:
    //Button( QString FileName, int num  = 1, QWidget *parent = 0);
    Button( QString FileName, int xnum  = 1,  QWidget *parent = 0, int ynum = 1);
    Button(QVector<QString> &list, QWidget *parent = 0);

private:
    void setPixmapList(QVector<QString> &list);

protected:
    QList<QPixmap> pixmatpList;
    int curIndex;
protected:
    virtual void paintEvent ( QPaintEvent * event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent ( QEvent * event );
    virtual void mousePressEvent ( QMouseEvent * event ) ;
    virtual void mouseReleaseEvent ( QMouseEvent * event );
    virtual  QSize sizeHint () const;

signals:

public slots:

};

#endif // CLOSEBUTTON_H
