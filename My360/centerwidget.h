#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include <basewidget.h>
#include <bottomwidget.h>
#include <QPair>
#include <QList>
#include <optimizecenterwidget.h>
#include <safecheckcenterwidget.h>
#include <cleancenterwidget.h>

class QStateMachine;
class QState;
class QSignalTransition;

class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);
    virtual ~CenterWidget();
signals:
    void closeBtnClicked();

public slots:
    void closeClicked();
    void startAnimation();
private:
    //QVBoxLayout *layout;
    TopBaseWidget *topWidget;
     bottomBaseWidget  *bottomWidget;

    OptimizeCenterWidget *lowerOptimizeCenter;
    SafeCheckCenterWidget *lowerSafeCenter;
    CleanCenterWidget *lowerCleanWidget;

    QStateMachine *topMoveMach ;
    QState *topMoveStart;
    QState *topMoveEnd;
    QSignalTransition *trans ;
   QPropertyAnimation *topMoveAnimation;

    void InitAnimation(void);
     void InitUi(void);
     void InitConnect(void);
};

#endif // CENTERWIDGET_H
