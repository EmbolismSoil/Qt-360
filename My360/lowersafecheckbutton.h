#ifndef LOWERSAFECHECKBUTTON_H
#define LOWERSAFECHECKBUTTON_H
#include <closebutton.h>

#include <closebutton.h>
#include <QWidget>
#include <QPropertyAnimation>

class lowerSafeCheckButton : public Button
{
    Q_OBJECT
public:
    lowerSafeCheckButton(QString path, QString AnimationPath, QWidget* = 0);

protected:
    virtual void paintEvent ( QPaintEvent * event);
    virtual void enterEvent(QEvent *event);

public slots:
    void AnimationEnd(){curPixmap = getPixmapList();}

private:
    QList<QPixmap>  pixmapAnimation;
    QList<QPixmap>   *curPixmap;

    QPropertyAnimation *hoverAnimation;
    void InitAnimation();
    void InitConnect();
};

#endif // LOWERSAFECHECKBUTTON_H
