#ifndef SAFECHECKCENTERWIDGET_H
#define SAFECHECKCENTERWIDGET_H
#include <QWidget>
#include <abslowercenterwidget.h>

class SafeCheckCenterWidget : public AbsLowerCenterWidget
{
public:
    SafeCheckCenterWidget(QWidget *parent);
private:
    virtual void InitUi(void);
};

#endif // SAFECHECKCENTERWIDGET_H
