#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <titlebar.h>
#include <loginbutton.h>
#include <nunberwidget.h>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>

class TopBaseWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QPointF AnimationPos READ getAnimationPos WRITE setAnimationPos)
    Q_PROPERTY(qreal Opacity READ getOpacity WRITE setOpacity)

public:
    explicit TopBaseWidget(QWidget *parent = 0);
    virtual ~TopBaseWidget();

    titleBar *getTitleBar(void){return title;}
    typedef  enum {MoveUp, MoveDonw, MoveLeft, MoveRight}MoveDirection;

    void setAnimationPos(const QPointF &a){AnimationPos = a; this->move(a.x(), a.y());}
    QPointF getAnimationPos(void){return AnimationPos;}

    qreal getOpacity(void){return  Effect->opacity();}
    void setOpacity(qreal opc){Effect->setOpacity(opc);}

    QPropertyAnimation *InAnimation(void){return inAnimation;}
    QPropertyAnimation *OutAnimation(void){return outAnimation;}
signals:

public slots:
    void startAnimation(void);
protected:
    virtual void paintEvent ( QPaintEvent * event);

private:
    titleBar *title;
    Button *examineBtn;
    Button *safeBtn;
    Button *payinBtn;
    Button *lineBtn;

    LoginButton *loginBtn;
    NunberWidget *number;
    QPixmap *backGround;

    QPropertyAnimation *outAnimation;
    QPropertyAnimation *inAnimation;
    QPropertyAnimation *outOpacityAnimation;
    QPropertyAnimation *inOpacityAnimation;
    QParallelAnimationGroup *inGroup;
    QParallelAnimationGroup *outGroup;
    QGraphicsOpacityEffect *Effect;

    QPointF AnimationPos;
    qreal Opacity;
    bool m_isOut;
    void IinitAnimatio(void);
    void IinitUi(void);
    void InitConnect(void);
};

#endif // BASEWIDGET_H
