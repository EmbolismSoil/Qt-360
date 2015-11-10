#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QWidget>

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
    QPixmap *BackGround;
};

#endif // BOTTOMWIDGET_H
