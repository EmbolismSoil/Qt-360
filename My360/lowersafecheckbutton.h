#ifndef LOWERSAFECHECKBUTTON_H
#define LOWERSAFECHECKBUTTON_H
#include <closebutton.h>

#include <closebutton.h>
#include <QWidget>
#include <QPropertyAnimation>
#include <QTimeLine>
#include <QTimer>

class lowerSafeCheckButton : public Button
{
    Q_OBJECT
public:
    lowerSafeCheckButton(QString path, QString AnimationPath, QWidget* = 0);
    virtual ~lowerSafeCheckButton();
protected:
    virtual void paintEvent ( QPaintEvent * event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent ( QEvent * event );
    virtual void mousePressEvent ( QMouseEvent * event ) ;

public slots:
    void Animation(){ curPixmap = getPixmapList(); curIndex = 1; update();}
private:
    QList<QPixmap>  pixmapAnimation;
    QList<QPixmap>   *curPixmap;
    QPropertyAnimation *animation;

    void InitAnimation();
    void InitConnect();
};

#endif // LOWERSAFECHECKBUTTON_H
