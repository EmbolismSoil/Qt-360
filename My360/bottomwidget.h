#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QWidget>
#include <closebutton.h>
#include <QHBoxLayout>
#include <buttonwithname.h>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>

class bottomBaseWidget : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QPointF AnimationPos READ getAnimationPos WRITE setAnimationPos)
    Q_PROPERTY(qreal Opacity READ getOpacity WRITE setOpacity)

public:
    explicit bottomBaseWidget(QWidget *parent = 0);
     ButtonWithName *getOptimizeBtn(void){return optimizeBtn;}

     void setAnimationPos(const QPointF &a){AnimationPos = a; this->move(a.x(), a.y());}
     QPointF getAnimationPos(void){return AnimationPos;}

     qreal getOpacity(void){return  Effect->opacity();}
     void setOpacity(qreal opc){Effect->setOpacity(opc);}

protected:
    //virtual void paintEvent ( QPaintEvent * event);
    //virtual QSize	sizeHint () const;
signals:

public slots:
     void startAnimation(void);
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

    QPropertyAnimation *outAnimation;
    QPropertyAnimation *inAnimation;
    QPropertyAnimation *outOpacityAnimation;
    QPropertyAnimation *inOpacityAnimation;
    QParallelAnimationGroup *inGroup;
    QParallelAnimationGroup *outGroup;

    QPointF AnimationPos;
    QGraphicsOpacityEffect *Effect;
    qreal Opacity;
    bool m_isOut;

    void InitUi(void);
    void InitAnimation(void);
    void InitConnect(void);

};

#endif // BOTTOMWIDGET_H
