#ifndef CLEANCENTERWIDGET_H
#define CLEANCENTERWIDGET_H
#include <abslowercenterwidget.h>

class CleanCenterWidget : public AbsLowerCenterWidget
{
public:
    CleanCenterWidget(QWidget *parent = 0);
private:
    virtual void InitUi(void);
};

#endif // CLEANCENTERWIDGET_H
