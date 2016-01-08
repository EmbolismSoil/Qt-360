#ifndef NUNBERWIDGET_H
#define NUNBERWIDGET_H

#include <QWidget>
#include <QString>
#include <QVector>
#include <QPixmap>
#include <QList>

class NunberWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NunberWidget(QWidget *parent = 0);
    virtual ~NunberWidget();
    void setNum(int num);
private:
    QList<int> index;
    QVector<QPixmap> pixmapVec;
    QPixmap *background;

protected:
    virtual void paintEvent ( QPaintEvent * event);
    virtual  QSize sizeHint () const;

signals:

public slots:

};

#endif // NUNBERWIDGET_H
