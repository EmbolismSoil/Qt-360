#ifndef OPTIMIZECENTERWIDGET_H
#define OPTIMIZECENTERWIDGET_H

#include <abslowercenterwidget.h>
class OptimizeCenterWidget : public AbsLowerCenterWidget
{
public:
    OptimizeCenterWidget(QWidget *parent);
private:
    virtual void InitUi(void);
};

#endif // OPTIMIZECENTERWIDGET_H
