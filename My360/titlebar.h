#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <closebutton.h>
#include <QHBoxLayout>


class titleBar : public QWidget
{
    Q_OBJECT
public:
    explicit titleBar(QWidget *parent = 0);
    Button *getCloseBtn() const {return closeBtn;}
    Button *getMinimizeBtn() const {return minimizeBtn;}
    void InsertUserLayout(QLayout *UserLayout, int pos, int stretch);
    void InsertUserWidget(QWidget *widget, int index, int stretch = 0, Qt::Alignment alignment = 0)
    {
        layout->insertWidget(index, widget, stretch, alignment);
    }

protected:
    //virtual void UserLayoutInit(void);

private:
    Button *closeBtn;
    Button *minimizeBtn;
    Button *menuBtn;
    Button *skinBtn;
    Button *videoBtn;

   // QGridLayout *layout;
    QHBoxLayout* layout;
    void WidgetLayoutInit(void);

signals:

public slots:

};


#endif // TITLEBAR_H
