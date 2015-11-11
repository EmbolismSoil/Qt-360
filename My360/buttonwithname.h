#ifndef BUTTONWITHNAME_H
#define BUTTONWITHNAME_H

#include <QWidget>
#include <closebutton.h>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>


class ButtonWithName : public QWidget
{
    Q_OBJECT
public:
    ButtonWithName( QString FileName, int xnum  = 1,  QWidget *parent = 0, int ynum = 1, QString name = 0);
    ButtonWithName(QVector<QString> &list, QWidget *parent = 0, QString name = 0);

    void SetBackGround(QString path, int xnum, int ynum);
    void setSpacing(int space){ layout->setSpacing(space); }
    void setFontSize(int size){  font->setPointSize(size); nameLabel->setFont(*font);}

signals:

public slots:

protected:
    virtual void paintEvent ( QPaintEvent * event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent ( QEvent * event );
    virtual  QSize sizeHint () const;

private:
    QLabel *nameLabel;
    QGroupBox *Group;
    Button *Btn;
    QFont *font;
    QVBoxLayout *layout;
    QPalette *palette;
    QList<QPixmap> backGd;
    bool m_isEnter;
};

#endif // BUTTONWITHNAME_H
