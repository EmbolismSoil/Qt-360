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


class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);

signals:
    void closeBtnClicked();

public slots:
    void closeClicked();
    void startAnimation();
private:
    QVBoxLayout *layout;
    TopBaseWidget *topWidget;
     bottomBaseWidget  *bottomWidget;

    OptimizeCenterWidget *lowerOptimizeCenter;
    SafeCheckCenterWidget *lowerSafeCenter;
    CleanCenterWidget *lowerCleanWidget;

    void InitAnimation(void);
     void InitUi(void);
     void InitConnect(void);
};

#endif // CENTERWIDGET_H
